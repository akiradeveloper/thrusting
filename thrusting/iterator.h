#pragma once

/*
  Helper functions for iterator objects.
*/

#include <thrust/iterator/iterator_traits.h>
#include <thrust/advance.h>

namespace thrusting {

namespace detail {

template<typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_of(Iterator it, thrust::host_space_tag){
  return *(it);
}

template<typename Iterator>
__host__ __device__
typename thrust::iterator_value<Iterator>::type iterator_value_of(Iterator it, thrust::device_space_tag){
  return *(it);
}

template<typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_of(Iterator it, thrust::any_space_tag){
  return *(it);
}

template<typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_of(Iterator it){
  return iterator_value_of(it, typename thrust::iterator_space<Iterator>::type());
}

template<typename Index, typename Iterator>
__host__ __device__
typename thrust::iterator_value<Iterator>::type iterator_value_at(Index n, Iterator it, thrust::device_space_tag){
  it += n;
  return detail::iterator_value_of(it, thrust::device_space_tag());
}

template<typename Index, typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_at(Index n, Iterator it, thrust::host_space_tag){
  thrust::advance(it, n);
  return detail::iterator_value_of(it, thrust::host_space_tag());
}

template<typename Index, typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_at(Index n, Iterator it, thrust::any_space_tag){
  it += n;
  return detail::iterator_value_of(it, thrust::host_space_tag());
}

} // END detail

template<typename Index, typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_at(Index n, Iterator it){
  return detail::iterator_value_at(n, it, typename thrust::iterator_space<Iterator>::type());
}

template<typename Distance, typename Iterator>
Iterator advance(Distance distance, Iterator it){
  thrust::advance(it, distance);
  return it;
}

template<typename Index, typename Iterator>
void alloc_at(Index idx, Iterator it, typename thrust::iterator_value<Iterator>::type x){
  thrust::advance(it, idx);
  *it = x;
}

} // END thrusting
