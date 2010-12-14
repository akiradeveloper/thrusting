require "#{ENV["HOME"]}/.thrusting/configure.rb"

module Thrusting

  class << self

    private

    def use_cuda(cc)
      cuda_home = get_cuda_home()
      cuda_lib = [cuda_home, "lib"].join "/"
      cc += " -L #{cuda_lib}"
      if get_machine_bit() == "64"
        cc += "64"
      end
      return cc
    end

    def use_thrust(cc)
      thrust_home = get_thrust_home() 
      thrust_include = thrust_home
      cc += " -I #{thrust_include}"
      return cc
    end
    
    def use_thrusting(cc)
      thisdir = File.expand_path File.dirname __FILE__ 
      libpath = [thisdir, "..", ".."].join "/"
      libpath = File.expand_path libpath
      cc += " -I #{libpath}"
      return cc
    end
    
    
    def use_floating(cc, type)
      case type
      when "double"
        cc += " -D THRUSTING_USING_DOUBLE_FOR_REAL"
        return cc
      when "float"
        return cc
      else
        raise "invalid name"
      end
    end
    
  end

  module_function
  def use_device(cc, backend)
    case backend 
    when "host"
      return cc
    when "device"
      cc += " -D THRUSTING_USING_DEVICE_VECTOR"
      cc += " -D THRUST_DEVICE_BACKEND=THRUST_DEVICE_BACKEND_CUDA"
      return cc
    when "omp" 
      cc += " -D THRUSTING_USING_DEVICE_VECTOR"
      cc += " -Xcompiler -fopenmp"
      cc += " -D THRUST_DEVICE_BACKEND=THRUST_DEVICE_BACKEND_OMP"
      return cc
    else
      raise "invalid name"
    end
  end 

  def use_mode(cc, mode, backend)
    case mode
    when "release"
      cc += " -O2" # optimized
      return cc
    when "debug"
      cc += " -g"
      if backend != "host" and debug_on_device?()
        cc += " -G"
      end
      return cc
    else
      raise "invalid type"
    end 
  end
  
  def make_default_compiler(cc)
    cc = use_cuda(cc)
    cc = use_thrust(cc)
    cc = use_thrusting(cc)
    cc = use_floating(cc, get_floating_type())
    return cc
  end

  def use_gtest(cc)
    thisdir = File.expand_path File.dirname __FILE__
    gtest_home = get_gtest_home()
    gtest_lib = [gtest_home, "lib"].join "/"
    gtest_include = [gtest_home, "include"].join "/"
    cc += " -Xcompiler -trigraphs "
    cc += " -I #{gtest_include}"
    cc += " -L #{gtest_lib}"
    cc += " -l gtest"
    cc += " #{thisdir}/gtest_main.cu"
    return cc
  end
end

if __FILE__ == $0
  cc = "nvcc"
  p Thrusting.make_default_compiler(cc)
end
