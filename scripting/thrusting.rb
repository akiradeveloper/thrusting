["generate", "buildenv", "plot", "run"].each do |f|
  require "thrusting/#{f}"
end
