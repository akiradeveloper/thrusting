thisdir = File.expand_path File.dirname __FILE__

require "rake/clean"
require "#{thisdir}/../configure"

["math", "generate", "buildenv", "plot", "run"].each do |f|
  require "thrusting/#{f}"
end

module Thrusting
  class << self
    include Thrusting
  end

  module_function
  def private_module_function(*names)
    names.each do |name|
      module_function name
      private_class_method name
    end
  end

end
