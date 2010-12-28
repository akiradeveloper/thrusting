thisdir = File.expand_path File.dirname __FILE__

["nvcc_config"].each do |f|
  require "#{thisdir}/#{f}"
end

module Thrusting

  class << self
    include Thrusting
  end
   
  DEFAULT_OPTIMIZE_FLAG = "-O2"

  def make_default_compiler
    return Compiler.new("nvcc")
  end

  RUNNABLE_DEVICES = ["host", "omp", "device"]
  def get_runnable_devices
    # if pre-Fermi, not worth run on devices except host risking runtime error
    if pre_fermi?
      return ["host"]
    end
    return RUNNABLE_DEVICES
  end

  # not implemented yet
  def make_cat_task(dir)
    namespace :cat do
      get_runnable_devices.each do |dev|
        task "on_all" => "on_#{dev}" do |t|
        end
        task "on_#{dev}" => "#{dir}/on_#{dev}" do |t|
        end
      end
    end
  end

  class Compiler

    include Thrusting

    def initialize(cmd)
      @cmd = cmd
      @backend = "host"
      @enable_debug = false
      @use_gtest = false
      @realtype = "float"
      @append = []
    end

    def make_compile_task(dir, devices=get_runnable_devices)
      files = FileList["#{dir}/*.h"]
      files.each do |f|
        name = File.basename(f, ".h")
        runnable_devices = [devices].flatten
        runnable_devices.each do |dev|
          binname = "#{name}_on_#{dev}.bin"
          file "#{dir}/#{binname}" => f do |t|
            cuname = "#{name}.cu"

            tmp = File.open("#{dir}/#{cuname}", "w")
            txt =
            """
            #include \"#{name}.h\"
            """
            tmp.write(txt)
            tmp.close

            cc = self.deepcopy
            cc = cc.use_backend(dev)

            sh "#{cc.to_s} -o #{dir}/#{binname} #{dir}/#{cuname}"
            FileUtils.rm("#{dir}/#{cuname}")
          end

          namespace :compile do
            task dir => "#{dir}/#{binname}"
            task :all => dir
          end

          namespace :clobber do
            task dir do
              sh "rm -rf #{dir}/#{binname}"
            end
          end

          CLOBBER.include("#{dir}/#{binname}")
        end
      end
    end

    def make_gtest_task(dir, devices=get_runnable_devices)
      make_cat_task(dir)

      hs = FileList["#{dir}/*.h"].exclude("#{dir}/all.h")
      file "#{dir}/all.h" => hs do |t|
        f = File.open(t.name, "w")
        f.write("#pragma once\n")
        txt = hs.map { |h| "#include \"#{File.basename(h)}\"" }.join "\n"
        f.write(txt)
        f.close
      end
      # CLOBBER.include("#{dir}/all.h")
    
      cc = self.deepcopy
      runnable_devices = [devices].flatten
      cc.use_gtest.make_compile_task(dir, runnable_devices)
   
      outputdir = "#{dir}/regression/#{get_machine_name()}"
      FileUtils.mkdir_p(outputdir)

      namespace :regress do
        runnable_devices.each do |dev|
          binname = "#{dir}/all_on_#{dev}.bin"
          file binname => "#{dir}/all.h"
          task "on_#{dev}" => binname do |t|
            sh "#{binname} | tee #{outputdir}/#{dev}"
          end
          task :on_all => "on_#{dev}" 
        end
      end
    end

    def deepcopy
      return Marshal.load Marshal.dump(self)
    end

    def enable_debug_mode
      @enable_debug = true
      self
    end

    def use_backend(backend)
      @backend = backend
      self
    end

    # use type as real
    # if not possible in your environment, exception thrown.
    def use_real_precision(type)
      if type == "double"
        unless enable_double_precision?
          msg =
          """
          your environment does not support double precision.
          """
          raise msg
        end
      end
      @realtype = type
      self
    end

    def append(option)
      unless @append.include? option 
        @append << option
      end
      self
    end

    def to_s
      cxx = @cmd

      cxx = using_cuda(cxx)
      cxx = using_thrust(cxx)
      cxx = using_thrusting(cxx)
  
      cxx = using_backend(cxx, @backend)

      if @enable_debug
        cxx = using_debug_mode(cxx, @backend)
      end

      cxx = using_real_precision(cxx, @realtype)
    
      @append.each do |a|
        cxx += " #{a}"
      end

      if @use_gtest
        cxx = using_gtest(cxx)
      end

      return cxx
    end

    ### private ###
    protected
    def use_gtest
      @use_gtest = true
      self
    end

    private
    def using_gtest(cxx)
      thisdir = File.expand_path File.dirname __FILE__
      conf = `gtest-config --cxxflags --cppflags --ldflags --libs`
      conf = conf.gsub("-pthread") { |x| "-Xcompiler -pthread" }
      cxx += " #{conf.rstrip}"
      cxx += " -Xcompiler -trigraphs"
      cxx += " #{thisdir}/gtest_main.cu"
      return cxx
    end

    def using_cuda(cxx)
      cxx += " -arch=#{get_gpu_sm}"
      cxx = nvcc_config(cxx)
      return cxx
    end

    def using_thrust(cxx)
      homepath = get_thrust_home 
      incpath = homepath
      cxx += " -I #{incpath}"
      return cxx
    end
    
    def get_thrust_home
      return THRUST_DIR
    end

    def using_thrusting(cxx)
      thisdir = File.expand_path File.dirname __FILE__ 
      incpath = [thisdir, "..", ".."].join "/"
      incpath = File.expand_path incpath
      cxx += " -I #{incpath}"
      return cxx
    end
    
    def using_real_precision(cxx, type)
      case type
      when "double"
        cxx += " -D THRUSTING_USING_DOUBLE_FOR_REAL"
        return cxx
      when "float"
        return cxx
      else
        raise "@#{__FILE__} use floating invalid type"
      end
    end

    def enable_double_precision?
      return (not pre_fermi?)
    end

    def using_backend(cxx, backend)
      case backend 
      when "host"
        return cxx
      when "device"
        cxx += " -D THRUSTING_USING_DEVICE_VECTOR"
        cxx += " -D THRUST_DEVICE_BACKEND=THRUST_DEVICE_BACKEND_CUDA"
        return cxx
      when "omp" 
        cxx += " -D THRUSTING_USING_DEVICE_VECTOR"
        cxx += " -D THRUST_DEVICE_BACKEND=THRUST_DEVICE_BACKEND_OMP"
        cxx += " -Xcompiler -fopenmp"
        return cxx
      else
        raise "@#{__FILE__} use device invalid backend"
      end
    end

    def using_debug_mode(cxx, backend)
      cxx += " -g"
      cxx += " -D THRUST_DEBUG"
      cxx += " -D THRUSTING_DEBUG"
      if backend == "device" and debug_on_device?
        cxx += " -G"
      end
      return cxx
    end
    
    def debug_on_device?
      if pre_fermi?
        return false
      end
      return DEBUG_ON_DEVICE
    end
  end 
end

if __FILE__ == $0
  # TEST
  include Thrusting
  make_default_compiler()
  .enable_backend("omp").enable_backend("device").use_float_type("double").enable_gtest
  .append(DEFAULT_OPTIMIZE_FLAG)
  .append("-O3")
  .append("-O3")
  .to_s

  get_runnable_devices
end
