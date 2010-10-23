#pragma once

#include <thrust/host_vector.h>

namespace thrusting {

template<typename T>
thrust::host_vector<T> &make_host_vector(size_t n, ...){
  thrust::host_vector<T> xs(n);
  va_list values;
  va_start(values, n);
  for(size_t i=0; i<n; i++){
    xs.push_back(va_arg(values, T));
  }
  va_end(values);  
  return xs; 
}

}
