module Thrusting
  home = ENV["HOME"]

  # user configuration
  THRUST_DIR = "#{home}/sandbox/thrusting"
  FLOAT_TYPE = "float"
  DEBUG_ON_DEVICE = false
  DEVICE_ID = 0
  RUNNABLE_DEVICES = ["host", "omp", "device"]
  MACHINE_NAME = "GTS450"
end
