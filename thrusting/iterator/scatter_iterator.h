#pragma once

#include <thrust/sort.h>
#include <thrust/sequence.h>
#include <thrust/iterator/permutation_iterator.h>

namespace thrusting {

template<
typename Size, 
typename ElementIterator, 
typename IndexIterator1,
typename IndexIterator2>
thrust::permutation_iterator<ElementIterator, IndexIterator2>
make_scatter_iterator(
  Size len,
  ElementIterator elem,
  IndexIterator1 index,
  IndexIterator2 index_tmp
){
  /*
    index_tmp = [0,...len-1]
  */
  thrust::sequence(
    index_tmp,
    thrusting::advance(len, index_tmp));

  thrust::sort_by_key(
    index,
    thrusting::advance(len, index),
    index_tmp); 

  return thrust::make_permutation_iterator(elem, index_tmp);
}

} // END thrusting
