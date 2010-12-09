def use_cuda(cc)
  cuda_home = "/usr/local/cuda"
  cuda_lib = [cuda_home, "lib"].join "/"
  cc += " -L #{cuda_lib}"
end
