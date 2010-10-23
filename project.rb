thisdir = File.dirname(__FILE__)

THRUST_HOME = "#{ENV["HOME"]}/local/thrust"
THRUST_INCLUDE = THRUST_HOME

LIBPATH = thisdir
VERSION = "0.0.0"
DEVELOPER = ["Akira Hayakawa <ruby.wktk@gmail.com>"]
cc = "nvcc"
cc = [cc, THRUST_INCLUDE, LIBPATH].join " -I"
CC = cc

p CC
