#pragma once

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

/*
  Akira Hayakawa 2010 10/9
  Here we are using Macro.
  This is little bit periling
  because it aborts type checking.
  Using type constructor will enable type checking however,
  the client code will be unnatural as of
  
  thrusting<int>::vector _xs;
  
  althought we hope to be writing as
  
  thrusting::vector<int> _xs;

  This will be possible in next C++0x but,
  nvcc does not support or will not support forever.
  After all we decided to use Macro.
*/
#ifdef THRUSTING_USING_DEVICE_VECTOR
  #define THRUSTING_VECTOR thrust::device_vector 
#else
  #define THRUSTING_VECTOR thrust::host_vector
#endif
