thisdir = File.expand_path File.dirname __FILE__

["compile", "gtest", "plot", "run"].each do |f|
  require "#{thisdir}/task/#{f}"
end
