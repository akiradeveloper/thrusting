#pragma once

/*
  You can switch vector type by adding 

  -D THRUSTING_USING_DEVICE_VECTOR

  This is useful for building a portable software where
  you can benchmark the performance of your software between GPU and CPU
  without modified here and there in your software.
  
  Use 
  
  thrusting::vector<datatype>::type 

  instead writing thrust::device_vector or thrust::host_vector
  then you will be more easy to investigate GPU/CPU performance acceleration!
*/

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

namespace thrusting {

template<typename T>
struct vector {
#ifdef THRUSTING_USING_DEVICE_VECTOR
  typedef typename thrust::device_vector<T> type; 
#else
  typedef typename thrust::host_vector<T> type;
#endif
};

} // END thrusting
