thisdir = File.expand_path File.dirname __FILE__ 

require [thisdir, "def_compile"].join "/"

def compile(src, bin)
  system "#{TESTCC} -D THRUSTING_USE_DEVICE_VECTOR -o #{bin} #{src}"  
end

if __FILE__ == $0
  src = ARGV[0]
  if File.extname(src) == ".cu"
    # ruby compile.rb hoge.cpp
    bin = File.basename(src, ".cu") + ".test"
    compile(src, bin) 
    run(bin)
  end
end
