module Thrusting
  class << self
    include Thrusting
  end
  
  # user configuration
  private
  home = ENV["HOME"]

  # Thrust Library must be pre-installed.
  THRUST_DIR = "#{home}/local/thrust"
  
  # using -G option for debugging mode on device code.
  # this will drastically increase the compilation time.
  DEBUG_ON_DEVICE = true

  # This name is used for making directory for storing data
  # such as the result of regression test.
  MACHINE_NAME = "GTS450"
end
