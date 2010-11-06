# describing overall configuration of compilation

thisdir = File.expand_path File.dirname __FILE__ 

LIBPATH = [thisdir, "..", ".."].join "/"

THRUST_HOME = "#{ENV["HOME"]}/local/thrust"
THRUST_INCLUDE = THRUST_HOME

cc = "nvcc"
cc = [cc, THRUST_INCLUDE, LIBPATH].join " -I"

CUDA_HOME = "/usr/local/cuda"
CUDA_LIB = [CUDA_HOME, "lib"].join "/"

cc = [cc, CUDA_LIB].join " -L"

CC = cc
