# This path should be changed by client
THRUST_HOME = "#{ENV["HOME"]}/local/thrust"
THRUST_INCLUDE = THRUST_HOME

GTEST_HOME = "#{ENV["HOME"]}/local/cunit/cunit-2.1-2"
GTEST_LIB = [GTEST_HOME, "lib"].join "/"
GTEST_INCLUDE = [GTEST_HOME, "include"]. join "/"

thisdir = File.dirname(__FILE__)
LIBPATH = thisdir
VERSION = "0.0.0"
DEVELOPER = ["Akira Hayakawa <ruby.wktk@gmail.com>"]
COMPILER = "nvcc"
#CC = [COMPILER, LIBPATH, THRUST_INCLUDE].join " -I "
CC = COMPILER
testcc = CC
testcc = [testcc, CUNIT_INCLUDE].join " -I"
testcc = [testcc, CUNIT_LIB].join " -L"
testcc = [testcc, "cunit"].join " -l"
TESTCC = testcc

#p CC
p TESTCC
