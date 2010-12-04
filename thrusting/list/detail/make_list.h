#pragma once

#include <thrusting/list.h>

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <sstream>

namespace thrusting {

template<typename Iterator>
list<Iterator> make_list(size_t n, Iterator head){
  return list<Iterator>(n, head);
}

template<typename T>
list<typename thrust::device_vector<T>::const_iterator> make_list(const thrust::device_vector<T> &xs){
  return make_list(xs.size(), xs.begin());
}

template<typename T>
list<typename thrust::host_vector<T>::const_iterator> make_list(const thrust::host_vector<T> &xs){
  return make_list(xs.size(), xs.begin());
}

} // end thrusting
