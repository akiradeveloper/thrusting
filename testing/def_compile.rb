thisdir = File.expand_path File.dirname __FILE__ 

LIBPATH = [thisdir, ".."].join "/"

THRUST_HOME = "#{ENV["HOME"]}/local/thrust"
THRUST_INCLUDE = THRUST_HOME

cc = "nvcc"
cc = [cc, THRUST_INCLUDE, LIBPATH].join " -I"

CUDA_HOME = "/usr/local/cuda"
CUDA_LIB = [CUDA_HOME, "lib"].join "/"

# gtest is 32bit
GTEST_HOME = "#{ENV["HOME"]}/local/gtest/gtest-1.5.0"
GTEST_LIB = [GTEST_HOME, "lib"].join "/"
GTEST_INCLUDE = [GTEST_HOME, "include"].join "/"

testcc = cc 
testcc = [testcc, GTEST_INCLUDE].join " -I"
testcc = [testcc, CUDA_LIB, GTEST_LIB].join " -L"
testcc = [testcc, "gtest"].join " -l"
testcc = [testcc, "-g"].join(" ")

TESTCC = testcc

p TESTCC

def run(bin)
  system "./#{bin}"
end
