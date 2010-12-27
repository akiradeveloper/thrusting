module Thrusting
  
  class << self
    include Thrusting
  end

  # machine information
  def get_machine_name 
    return MACHINE_NAME # USER SPECIFIC
  end

  private
  ALLOWED_DEVICES = ["sm_10", "sm_11", "sm_12", "sm_13", "sm_20", "sm_21"]

  # always use device of id 0
  DEVICE_ID = 0
  def get_gpu_sm
    return `gpu_sm.bin #{DEVICE_ID}`.strip
  end

  def pre_fermi?
    # this array is from build/build-env.py from Thrust library
    devices = ALLOWED_DEVICES
    return devices.index(get_gpu_sm()) < devices.index("sm_20")
  end

  def get_os_name
    if /linux/ =~ RUBY_PLATFORM
      return "linux"
    end
    if /darwin/ =~ RUBY_PLATFORM 
      return "darwin"
    end
    raise "@#{__FILE__} except linux or darwin will not be supported"
  end

  # 32 or 64
  def get_machine_bit
    # if on mac, always use 32 bit mode.
    # 64 bit on mac is error prone.
    if get_os_name == "darwin"
      return 32
    end
    # hoping this will work
    if `uname -m` == 'x86_64'
      return 64
    end
    return 32
  end

  def get_num_cores
    case get_os_name
    when "darwin"
      n = get_num_cores_mac
      assert_num_cores(n)
      return n
    when "linux"
      n = get_num_cores_linux
      assert_num_cores(n)
      return n
    else
      raise "@#{__FILE__} either mac or linux supported"
    end      
  end

  REALISTIC_NUM_CORES = 8
  def assert_num_cores(n)
    unless n.kind_of? Integer and n <= REALISTIC_NUM_CORES
      raise "Number of Core should be integer and leq than #{REALISTIC_NUM_CORE}"
    end 
  end

  def get_num_cores_mac
    return `sysctl -n hw.ncpu`.to_i
  end

  def get_num_cores_linux
    s = `cat /proc/cpuinfo`
    return s.split("\n").find { |x| x.include? "cpu cores" }.split(":")[1].to_i
  end
end

if __FILE__ == $0
  include Thrusting
  p get_machine_bit
  p get_gpu_sm
  p get_num_cores
end
