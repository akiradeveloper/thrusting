thisdir = File.expand_path File.dirname __FILE__ 

["def_compile"].each do |s|
  require "thrusting/rb/#{s}"
end

# gtest is 32bit
GTEST_HOME = "#{ENV["HOME"]}/local/gtest/gtest-1.5.0"
GTEST_LIB = [GTEST_HOME, "lib"].join "/"
GTEST_INCLUDE = [GTEST_HOME, "include"].join "/"

cc = CC 
cc += " -I #{GTEST_INCLUDE}"
cc += " -L #{GTEST_LIB}"
cc += " -l gtest"
cc += " -g"

TEST_CC = cc

def compile_gtest(cc, bin, files)
  sources = ["gtest_main.cu"] + files
  compile(cc, bin, sources)
end
