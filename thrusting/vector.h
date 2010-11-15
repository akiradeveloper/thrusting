#pragma once

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

/*
  You can switch vector type instead of THRUSTING_VECTOR macro
  by adding "-D THRUSTING_USING_DEVICE_VECTOR".
  This is useful for building a portable software where
  you can benchmark the performance of your software between GPU and CPU
  without modified here and there in your software.
  
  Use THRUSTING_VECTOR instead writing "thrust::device_vector" or "thrust::host_vector"
  then you will be more easy to investigate GPU/CPU performance acceleration!
*/

/*
  Akira Hayakawa 2010 11/9
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
