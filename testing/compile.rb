thisdir = File.expand_path File.dirname __FILE__ 
require [thisdir, "def_compile"].join "/"

def compile(src, bin)
  system "#{TESTCC} -o #{bin} #{src}"  
end

if __FILE__ == $0
  src = ARGV[0]
  if File.extname(src) == ".cu"
    # ruby compile.rb hoge.cpp
    bin = File.basename(src, ".cu") + ".bin"
    compile(src, bin) 
    p "-----COMPILATION FINISHED-----"
    p "-----  START PROCESSING  -----"
    run(bin)
  end
end
