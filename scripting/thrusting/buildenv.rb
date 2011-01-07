thisdir = File.expand_path File.dirname __FILE__

["nvcc_config"].each do |f|
  require "#{thisdir}/#{f}"
end

require "#{thisdir}/../../configure"

module Thrusting

  class << self
    include Thrusting
  end
   
  def make_default_compiler
    return Compiler.new
  end

  RUNNABLE_DEVICES = ["host", "omp", "device"]
  def get_runnable_devices
    # if pre-Fermi, not worth run on devices except host risking runtime error
    if pre_fermi?
      return ["host"]
    end
    return RUNNABLE_DEVICES
  end

  def make_cat_task(dirs)
    _dirs = [dirs].flatten
    namespace :cat do
      get_runnable_devices.each do |dev|
        task "on_#{dev}" do |t|
          catfiles = ""
          _dirs.each do |d|
            catfiles += " #{get_outputfile(d, dev)}" 
          end
          sh "cat #{catfiles}"
        end
      end
    end
  end

  private 
  # directory for regression
  def get_outputdir(dir)
    "#{dir}/regression/#{get_machine_name()}"
  end

  def get_outputfile(dir, backend)
    get_outputdir(dir) + "/" + backend
  end

  public
  class Compiler

    include Thrusting

    def initialize
      @cmd = "nvcc"
      @backend = "host"
      @realtype = "float"
      @enable_debug = false
      @debug_on_device = false
      # -1 is no optimization
      @optimize_level = -1
      @use_gtest = false
      @append = []
    end

    def <<(option)
      append(option)
    end

    def optimize(level)
      unless [0,1,2,3].include? level
        raise "optimize level is 0,1,2,3"
      end
      @optimize_level = level
    end

    def disable_pretty_print
      append("-D THRUSTING_PRETTY_PRINT_DISABLED")
    end
   
    def disable_assertion
      append("-D THRUSTING_ASSERTION_DISABLED")
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
            cc.use_backend(dev)

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
      cc.use_gtest
      cc.make_compile_task(dir, runnable_devices)
   
      #outputdir = "#{dir}/regression/#{get_machine_name()}"
      outputdir = get_outputdir(dir)
      FileUtils.mkdir_p(outputdir)

      namespace :regress do
        runnable_devices.each do |dev|
          binname = "#{dir}/all_on_#{dev}.bin"
          file binname => "#{dir}/all.h"
          task "on_#{dev}" => binname do |t|
            #sh "#{binname} | tee #{outputdir}/#{dev}"
            sh "#{binname} | tee #{get_outputfile(dir, dev)}"
          end
          task :on_all => "on_#{dev}" 
        end
      end
    end

    def deepcopy
      return Marshal.load Marshal.dump(self)
    end

    def enable_debug_mode(debug_on_device=false)
      @enable_debug = true
      @debug_on_device = debug_on_device
      nil
    end

    def use_backend(backend)
      @backend = backend
      nil
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
      nil
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
    
      unless @optimize_level == -1
        append("-O#{@optimize_level}")
      end
    
      @append.each do |a|
        cxx += " #{a}"
      end

      if @use_gtest
        cxx = using_gtest(cxx)
      end

      return cxx
    end

    protected
    def use_gtest
      @use_gtest = true
      nil
    end

    ### private ###
    private

    def append(option)
      unless @append.include? option 
        @append << option
      end
      nil
    end

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

    def get_thrust_home
      return THRUST_DIR
    end

    def using_thrust(cxx)
      homepath = get_thrust_home 
      incpath = homepath
      cxx += " -I #{incpath}"
      return cxx
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
      if backend == "device" and debug_on_device?
        cxx += " -G"
      end
      return cxx
    end
    
    def debug_on_device?
      if pre_fermi?
        return false
      end
      return @debug_on_device
    end
  end 
end

if __FILE__ == $0
  # TEST
  include Thrusting

  cxx = make_default_compiler
  cxx.use_backend("omp")
  cxx.use_backend("device")
  cxx.use_real_precision("double")
  cxx.disable_pretty_print
  cxx.disable_assertion
  cxx << "-use_fast_math"

  p cxx
  p get_runnable_devices
end
