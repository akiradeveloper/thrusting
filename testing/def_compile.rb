thisdir = File.dirname(__FILE__)
require [thisdir, "..", "project"].join "/"

CUDA_HOME = "/usr/local/cuda"
CUDA_LIB = [CUDA_HOME, "lib"].join "/"

GTEST_HOME = "#{ENV["HOME"]}/local/gtest/gtest-1.5.0"
GTEST_LIB = [GTEST_HOME, "lib"].join "/"
GTEST_INCLUDE = [GTEST_HOME, "include"].join "/"

testcc = CC
testcc = [testcc, GTEST_INCLUDE].join " -I"
testcc = [testcc, CUDA_LIB, GTEST_LIB].join " -L"
testcc = [testcc, "gtest"].join " -l"
testcc = [testcc, "-m64", "-g", "-G"].join(" ")
TESTCC = testcc

p TESTCC

def run(bin)
  system "./#{bin}"
end
