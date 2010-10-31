#pragma once

#include <thrusting/list.h>

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <sstream>

namespace thrusting {

template<typename A>
detail::list<A> make_list(size_t n, A head){
  return detail::list<A>(n, head);
}

template<typename A>
detail::list<typename thrust::device_vector<A>::const_iterator> make_list(const thrust::device_vector<A> &xs){
  return make_list(xs.size(), xs.begin());
}

template<typename A>
detail::list<typename thrust::host_vector<A>::const_iterator> make_list(const thrust::host_vector<A> &xs){
  return make_list(xs.size(), xs.begin());
}

} // end thrusting
