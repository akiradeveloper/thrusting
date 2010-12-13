module Thrusting

def make_compiler(mode)
  cc = "nvcc"
  cc = use_cuda(cc)
  cc = use_thrust(cc)
  cc = use_thrusting(cc)
  cc = use_mode(cc, mode)
  cc = use_floating(cc, get_floating_type())
end

end # END Thrusting
