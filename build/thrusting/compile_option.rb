# type is host or device or omp
def with_device(cc, type)
  case type 
  when "host"
    cc
  when "device"
    cc += " -D THRUSTING_USING_DEVICE_VECTOR"
  when "omp" 
    cc += " -D THRUSTING_USING_DEVICE_VECTOR"
    cc += " -Xcompiler -fopenmp"
    cc += " -D THRUST_DEVICE_BACKEND=THRUST_DEVICE_BACKEND_OMP"
  else
    raise "invalid name"
  end
end

# type is float or double
def with_floating(cc, type)
  case type
  when "double"
    cc += " -D THRUSTING_USING_DOUBLE_FOR_REAL"
  when "float"
    cc
  else
    raise "invalid name"
  end
end

# mode is release or debug
def with_mode(cc, type)
  case type
  when "release"
    cc += " -O2" # optimized
  when "debug"
    cc += " -g"
  else
    raise "invalid type"
  end 
end
