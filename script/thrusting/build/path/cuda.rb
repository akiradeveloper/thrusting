module Thrusting 

def use_cuda(cc)
  cuda_home = get_CUDA_home()
  cuda_lib = [cuda_home, "lib"].join "/"
  cc += " -L #{cuda_lib}"
end

end # Thrusting
