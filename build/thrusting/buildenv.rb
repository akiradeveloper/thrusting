thisdir = File.expand_path File.dirname __FILE__ 

require "#{ENV["HOME"]}/.thrusting/configure.rb"

def use_cuda(cc)
  cuda_home = get_cuda_home()
  cuda_lib = [cuda_home, "lib"].join "/"
  cc += " -L #{cuda_lib}"
end

def use_thrust(cc)
  thrust_home = get_thrust_home() 
  thrust_include = thrust_home
  cc += " -I #{thrust_include}"
end

def use_thrusting(cc)
  libpath = [thisdir, "..", "..", "..", ".."].join "/"
  libpath = File.expand_path libpath
  cc += " -I #{libpath}"
end

def use_gtest(cc)
  gtest_home = get_gtest_home()
  gtest_lib = [gtest_home, "lib"].join "/"
  gtest_include = [gtest_home, "include"].join "/"
  cc += " -Xcompiler -trigraphs "
  cc += " -I #{gtest_include}"
  cc += " -L #{gtest_lib}"
  cc += " -l gtest"
  cc += " #{thisdir}/gtest_main.cu"
end

def use_device(cc, backend)
  case type 
  when "host"
    cc
  when "device"
    cc += " -D THRUSTING_USING_DEVICE_VECTOR"
    cc += " -D THRUST_DEVICE_BACKEND=THRUST_DEVICE_BACKEND_CUDA"
  when "omp" 
    cc += " -D THRUSTING_USING_DEVICE_VECTOR"
    cc += " -Xcompiler -fopenmp"
    cc += " -D THRUST_DEVICE_BACKEND=THRUST_DEVICE_BACKEND_OMP"
  else
    raise "invalid name"
  end
end

def use_floating(cc, type)
  case type
  when "double"
    cc += " -D THRUSTING_USING_DOUBLE_FOR_REAL"
  when "float"
    cc
  else
    raise "invalid name"
  end
end

def use_mode(cc, mode)
  case type
  when "release"
    cc += " -O2" # optimized
  when "debug"
    cc += " -g"
    if will_debug_on_device()
      cc += " -G"
    end
  else
    raise "invalid type"
  end 
end

def make_compiler(cc, mode, backend)
  cc = "nvcc"
  cc = use_cuda(cc)
  cc = use_thrust(cc)
  cc = use_thrusting(cc)
  cc = use_mode(cc, mode)
  cc = use_floating(cc, get_floating_type())
end
