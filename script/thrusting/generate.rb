thisdir = File.expand_path File.dirname __FILE__

["get_tuple", "make_autogen_task", "namespace.rb", "template_type", "tuple_min_max"].each do |f|
  require "thrusting/generate/#{f}"
end
