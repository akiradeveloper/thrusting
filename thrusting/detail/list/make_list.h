#pragma once

#include <thrusting/list.h>

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <sstream>

namespace thrusting {

template<typename A>
detail::list<A> make_list(size_t n, A head) {
  return list<A>(n, head);
}

template<typename T>
detail::list<A> make_list(thrust::device_vector<T> xs){
  return make_list(xs.size(), xs.begin());
}

template<typename T>
detail::list<A> make_list(thrust::host_vector<T> xs){
  return make_list(xs.size(), xs.begin());
}

} // end thrusting
