thisdir = File.expand_path File.dirname __FILE__

["plot", "run"].each do |f|
  require "#{thisdir}/task/#{f}"
end
