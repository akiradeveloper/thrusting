#pragma once

#include <thrust/binary_search.h>
#include <thrust/transform.h>
#include <thrust/iterator/counting_iterator.h>

#include <thrusting/iterator.h>

namespace thrusting {

/*
  sorted_int_array :: [Int] -> (prefix :: [Int], count :: [Int])
*/
template<typename IntIterator1, typename IntIterator2, typename IntIterator3>
void bucket_indexing(
  size_t n_idx,
  IntIterator1 idx, // Which cell the particle belongs to
  size_t n_bucket,
  IntIterator2 prefix, IntIterator3 count // output
){
  thrust::counting_iterator<size_t> search_begin(0);

  thrust::lower_bound(
    idx,
    thrusting::advance(n_idx, idx),
    search_begin,
    thrusting::advance(n_bucket, search_begin),
    prefix);

  thrust::upper_bound(
    idx,
    thrusting::advance(n_idx, idx),
    search_begin,
    thrusting::advance(n_bucket, search_begin),
    count);

  thrust::transform(
    count,
    thrusting::advance(n_bucket, count),
    prefix,
    count,
    thrust::minus<size_t>());
}

} // END thrusting
