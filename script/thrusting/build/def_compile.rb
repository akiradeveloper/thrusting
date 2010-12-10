["cuda", "thrust", "thrusting"].each do |f|
  require "thrusting/build/path/#{f}"
end

cc = "nvcc"

cc = use_cuda(cc)
cc = use_thrust(cc)
cc = use_thrusting(cc)

THRUSTING_CXX = cc
