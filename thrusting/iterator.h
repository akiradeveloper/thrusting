#pragma once

#include <thrust/iterator/iterator_traits.h>
#include <thrust/advance.h>

/*
  Helper functions for iterator objects.
*/
namespace thrusting {

namespace detail {
template<typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_of(Iterator it){
  return *(it);
}

} // END detail

template<typename Index, typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_at(Index n, Iterator it){
  thrust::advance(it, n);
  return detail::iterator_value_of(it);
}

// puzzling with thrust::advance(it, distance)
// argument ordering is reversed
template<typename Distance, typename Iterator>
Iterator advance(Distance distance, Iterator it){
  thrust::advance(it, distance);
  return it;
}

// name is little bit strange
template<typename Index, typename Iterator>
void alloc_at(Index idx, Iterator it, typename thrust::iterator_value<Iterator>::type x){
  // this might be lengthy.
  Iterator _it = thrusting::advance(idx, it);
  *_it = x;
}

} // END thrusting