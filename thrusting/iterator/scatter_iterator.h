#pragma once

#include <thrust/sort.h>
#include <thrust/sequence.h>
#include <thrust/iterator/permutation_iterator.h>

namespace thrusting {

template<
typename InputIterator1,
typename InputIterator2,
typename InputIterator3>
thrust::permutation_iterator<InputIterator1, InputIterator3>
make_scatter_iterator(
  InputIterator1 first,
  InputIterator1 last,
  InputIterator2 map,
  InputIterator3 tmp 
){
  /*
    index_tmp = [0,...len-1]
  */
  thrust::sequence(
    tmp,
    thrusting::advance(last-first, tmp));

  thrust::sort_by_key(
    map,
    thrusting::advance(last-first, map),
    tmp); 

  return thrust::make_permutation_iterator(first, tmp);
}

} // END thrusting
