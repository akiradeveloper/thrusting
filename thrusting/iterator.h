#pragma once

/*
  Helper functions for iterator objects.
*/

#include <thrust/iterator/iterator_traits.h>
#include <thrust/advance.h>

namespace thrusting {

namespace detail {

template<typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_of(Iterator it){
  return *(it);
}

} // END detail

template<typename Distance, typename Iterator>
Iterator advance(Distance distance, Iterator it){
  thrust::advance(it, distance);
  return it;
}

template<typename Index, typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_at(Index n, Iterator it){
  return detail::iterator_value_of(thrusting::advance(n, it));
}

template<typename Index, typename Iterator>
void alloc_at(Index idx, Iterator it, typename thrust::iterator_value<Iterator>::type x){
  thrust::advance(it, idx);
  *it = x;
}

} // END thrusting
