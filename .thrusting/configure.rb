module Thrusting 
  class << self
    private
    def get_cuda_home
      return "/usr/local/cuda"
    end
    
    def get_gtest_home
      return "#{ENV["HOME"]}/local/gtest/gtest-1.5.0" 
    end
    
    def get_thrust_home
      return "#{ENV["HOME"]}/local/thrust"
    end
    
    def get_os_name
      if /linux/ =~ RUBY_PLATFORM
        return "linux"
      end
      if /darwin/ =~ RUBY_PLATFORM 
        return "darwin"
      end
      raise "except linux or darwin will not be supported"
    end
    
    # machine information
    def get_machine_name 
      return "akiramacpro"
    end
    
    # 32 or 64
    def get_machine_bit
      if get_os_name() == "darwin"
        return 32
      end
      return 32 # user specified
    end
    
    def get_gpu_arch
      return "sm10" # user specified
    end
    
    def pre_fermi?
      devices = ["sm10", "sm11", "sm12", "sm20", "sm21"]
      return devices.index(get_gpu_arch()) < devices.index("sm20")
    end
    
    def get_runnable_devices
      # if pre-Fermi, not worth run on devices expect host risking
      if pre_fermi?()
        return ["host"]
      end
      return ["host", "omp", "devices"] # user specified
    end
    
    def debug_on_device?
      if pre_fermi?()
        return false
      end
      return false # user specified
    end
    
    def get_floating_type
      if pre_fermi?()
        return "float"
      end
      return "float" # user specified
    end
  end
end
