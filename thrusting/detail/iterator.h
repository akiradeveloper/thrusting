#pragma once

#include <thrust/iterator/iterator_traits.h>
#include <thrust/advance.h>

namespace thrusting {

// Akira Hayakawa, 2010 11/1 19:45
// tested only on host and device of 32 bit.
template<typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_of(Iterator it){
  return *(it);
}

template<typename Index, typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_at(Index n, Iterator it){
  thrust::advance(it, n);
  return thrusting::iterator_value_of(it);
}

} 
