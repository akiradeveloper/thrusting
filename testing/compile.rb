thisdir = File.dirname(__FILE__)
require [thisdir, "..", "project"].join "/"

GTEST_HOME = "#{ENV["HOME"]}/local/gtest/gtest-1.5.0"
GTEST_LIB = [GTEST_HOME, "lib"].join "/"
GTEST_INCLUDE = [GTEST_HOME, "include"].join "/"

testcc = CC
testcc = [testcc, GTEST_INCLUDE].join " -I"
testcc = [testcc, CUDA_LIB, GTEST_LIB].join " -L"
testcc = [testcc, "gtest"].join " -l"
testcc = [testcc, "-m64"].join(" ")
TESTCC = testcc

p TESTCC

def compile(src, bin)
  system "#{TESTCC} -o #{bin} #{src}"  
end

def run(bin)
  system "./#{bin}"
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
