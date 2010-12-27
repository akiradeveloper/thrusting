thisdir = File.expand_path File.dirname __FILE__

require "#{thisdir}/../configure"

["generate", "buildenv", "plot", "run"].each do |f|
  require "thrusting/#{f}"
end

module Thrusting
  module_function
  def private_module_function(name)
    module_function name
    private_class_method name
  end
end
