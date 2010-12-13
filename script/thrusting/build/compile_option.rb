module Thrusting 

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

end # Thrusting
