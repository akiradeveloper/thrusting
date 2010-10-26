#pragma once

#include <thrust/device_vector.h>

namespace thrust {

template<typename T>
thrust::device_vector<T> &make_device_vector(size_t n, ...){
  thrust::device_vector<T> xs(n);
  va_list values;
  va_start(values, n);
  for(size_t i=0; i<n; i++){
    xs.push_back(va_arg(values, T));
  }
  va_end(values);  
  return xs; 
}

}
