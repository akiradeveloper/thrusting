def use_thrusting(cc)
  thisdir = File.expand_path File.dirname __FILE__ 
  libpath = [thisdir, "..", ".."].join "/"
  libpath = File.expand_path libpath
  cc += " -I #{libpath}"
end
