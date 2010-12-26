thisdir = File.expand_path File.dirname __FILE__

["nvcc_config"].each do |f|
  require "#{thisdir}/#{f}"
end

module Thrusting
   
  DEFAULT_OPTIMIZE_FLAG = "-O2"

  class Compiler

    include Thrusting

    def initialize(cmd)
      @cmd = cmd
      @backend = "host"
      @enable_gtest = false
      @enable_debug = false
      @float_type = "float"
      @append = []
    end
    def make_compile_task(dir)
      files = FileList["#{dir}/*.h"]
      files.each do |f|
        name = File.basename(f, ".h")
        get_runnable_devices.each do |dev|
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
            cc = cc.enable_backend(dev)

            print "COMPILE_CMD: #{cc.to_s}"
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
    def make_gtest_task(dir)
      hs = FileList["#{dir}/*.h"].exclude("#{dir}/all.h")
      file "#{dir}/all.h" => hs do |t|
        f = File.open(t.name, "w")
        f.write("#pragma once\n")
        txt = hs.map { |h| "#include \"#{File.basename(h)}\"" }.join "\n"
        f.write(txt)
        f.close
      end
      CLOBBER.include("#{dir}/all.h")
    
      cc = self.deepcopy
      cc.make_compile_task(dir)
    
      outputdir = "#{dir}/regression/#{get_machine_name()}"
      FileUtils.mkdir_p(outputdir)
      namespace :regress do
        get_runnable_devices.each do |dev|
          task "on_#{dev}" => ["#{dir}/all.h", "#{dir}/all_on_#{dev}.bin"] do |t|
            sh "#{dir}/all_on_#{dev}.bin 1> #{outputdir}/#{dev}"
          end
          task :on_all => "on_#{dev}" 
        end
      end
    end
    def deepcopy
      return Marshal.load Marshal.dump(self)
    end
    def enable_gtest
      @enable_gtest = true
      self
    end
    def enable_debug
      @enable_debug = true
      self
    end
    def enable_backend(backend)
      @backend = backend
      self
    end
    def use_float_type(type)
      @float_type = type
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

      cxx = use_cuda(cxx)
      cxx = use_thrust(cxx)
      cxx = use_thrusting(cxx)
  
      cxx = use_backend(cxx, @backend)

      if @enable_debug
        cxx = use_debug(cxx, @backend)
      end

      cxx = use_floating(cxx, @float_type)
    
      @append.each do |a|
        cxx += " #{a}"
      end

      if @enable_gtest
        cxx = use_gtest(cxx)
      end

      return cxx
    end

    private
    def use_gtest(cxx)
      thisdir = File.expand_path File.dirname __FILE__
      conf = `gtest-config --cxxflags --cppflags --ldflags --libs`
      cxx += " #{conf.rstrip}"
      cxx += " -Xcompiler -trigraphs"
      cxx += " #{thisdir}/gtest_main.cu"
      return cxx
    end

    def use_cuda(cxx)
      cxx += " -arch=#{get_gpu_sm}"
      cxx = nvcc_config(cxx)
      return cxx
    end

    def use_thrust(cxx)
      homepath = get_thrust_home 
      incpath = homepath
      cxx += " -I #{incpath}"
      return cxx
    end
    
    def use_thrusting(cxx)
      thisdir = File.expand_path File.dirname __FILE__ 
      incpath = [thisdir, "..", ".."].join "/"
      incpath = File.expand_path incpath
      cxx += " -I #{incpath}"
      return cxx
    end
    
    def use_floating(cxx, type)
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

    def use_backend(cxx, backend)
      case backend 
      when "host"
        return cxx
      when "device"
        cxx += " -D THRUSTING_USING_DEVICE_VECTOR"
        cxx += " -D THRUST_DEVICE_BACKEND=THRUST_DEVICE_BACKEND_CUDA"
        return cxx
      when "omp" 
        ENV["OMP_NUM_THREADS"] = get_num_cores.to_s # not tested
        p ENV["OMP_NUM_THREADS"]
        cxx += " -D THRUSTING_USING_DEVICE_VECTOR"
        cxx += " -D THRUST_DEVICE_BACKEND=THRUST_DEVICE_BACKEND_OMP"
        cxx += " -Xcompiler -fopenmp"
        return cxx
      else
        raise "@#{__FILE__} use device invalid backend"
      end
    end

    def use_debug(cxx, backend)
      cxx += " -g"
      cxx += " -D THRUST_DEBUG"
      cxx += " -D THRUSTING_DEBUG"
      if backend == "device" and debug_on_device?
        cxx += " -G"
      end
      return cxx
    end

    THRUST_HOME = "#{ENV["HOME"]}/local/thrust" # USER SPECIFIC
    def get_thrust_home
      return THRUST_HOME
    end
    
    DEBUG_ON_DEVICE = false
    def debug_on_device?
      if pre_fermi?
        return false
      end
      return DEBUG_ON_DEVICE # USER SPECIFIC
    end
    
    FLOAT_TYPE = "float"
    def get_floating_type
      if pre_fermi?
        return "float"
      end
      return FLOAT_TYPE # USER SPECIFIC
    end
  end 

  module_function 
  def make_default_compiler
    return Compiler.new("nvcc")
  end

  def get_runnable_devices
    # if pre-Fermi, not worth run on devices except host risking runtime error
    if Detail::pre_fermi?
      return ["host"]
    end
    return ["host", "omp", "device"] # USER SPECIFIC
  end
end

if __FILE__ == $0
  # TEST
  p Thrusting.make_default_compiler()
  .enable_backend("omp").enable_backend("device").use_float_type("double").enable_gtest
  .append(Thrusting::DEFAULT_OPTIMIZE_FLAG)
  .append("-O3")
  .append("-O3")
  .to_s

  p Thrusting.get_runnable_devices
end
