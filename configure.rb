module Thrusting
  class << self
    include Thrusting
  end
  
  private
  home = ENV["HOME"]

  # Thrust Library must be pre-installed.
  THRUST_DIR = "#{home}/local/thrust"
  
  # This name is used for making directory for storing data
  # such as the result of regression test.
  MACHINE_NAME = "GTS450"
end
