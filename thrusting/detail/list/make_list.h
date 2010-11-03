#pragma once

#include <thrusting/list.h>

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <sstream>

namespace thrusting {

template<typename Iterator>
detail::list<Iterator> make_list(size_t n, Iterator head){
  return detail::list<Iterator>(n, head);
}

template<typename Iterator>
detail::list<typename thrust::device_vector<Iterator>::const_iterator> make_list(const thrust::device_vector<Iterator> &xs){
  return make_list(xs.size(), xs.begin());
}

template<typename Iterator>
detail::list<typename thrust::host_vector<Iterator>::const_iterator> make_list(const thrust::host_vector<Iterator> &xs){
  return make_list(xs.size(), xs.begin());
}

} // end thrusting
