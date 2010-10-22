# This path should be changed by client
THRUST_HOME = "#{ENV["HOME"]}/local/thrust"
THRUST_INCLUDE = THRUST_HOME

CUNIT_HOME = "#{ENV["HOME"]}/local/cunit/cunit-2.1-2"
CUNIT_LIB = [CUNIT_HOME, "lib"].join "/"
CUNIT_INCLUDE = [CUNIT_HOME, "include"].join "/"

GTEST_HOME = "#{ENV["HOME"]}/local/gtest/gtest-1.5.0"
GTEST_LIB = [GTEST_HOME, "lib"].join "/"
GTEST_INCLUDE = [GTEST_HOME, "include"].join "/"

CUDA_HOME = "/usr/local/cuda"
CUDA_LIB = [CUDA_HOME, "lib"].join "/"

thisdir = File.dirname(__FILE__)
LIBPATH = thisdir
VERSION = "0.0.0"
DEVELOPER = ["Akira Hayakawa <ruby.wktk@gmail.com>"]
COMPILER = "nvcc -m64"
CC = [COMPILER, LIBPATH, THRUST_INCLUDE].join " -I"
testcc = CC
testcc = [testcc, CUNIT_INCLUDE, GTEST_INCLUDE].join " -I"
testcc = [testcc, CUDA_LIB, CUNIT_LIB, GTEST_LIB].join " -L"
testcc = [testcc, "cunit", "gtest"].join " -l"
TESTCC = testcc

#p CC
p TESTCC
