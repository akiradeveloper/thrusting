#pragma once

#include <thrust/device_vector.h>

namespace thrusting {

template<typename T>
thrust::device_vector<T> &make_device_vector(int n, ...){
  thrust::device_vector<T> xs;
  va_list values;
  va_start(values, n);
  for(int i=0; i<n; i++){
    xs.push_back(var_arg(values, T));
  }
  va_end(values);  
  return xs; 
}

}
