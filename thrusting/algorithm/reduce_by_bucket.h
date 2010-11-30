#pragma once

#include <thrust/reduce.h>
#include <thrust/transform.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/scatter.h>

#include <thrusting/algorithm/bucket_indexing.h>
#include <thrusting/iterator.h>
#include <thrusting/functional.h>
#include <thrusting/algorithm/safe_scatter.h>

namespace thrusting {
  
template<
typename Size1,
typename Size2,
typename InputIterator1,
typename InputIterator2,
typename OutputIterator1,
typename OutputIterator2,
typename OutputIterator3,
typename T>
void reduce_by_bucket(
  Size1 n_value,
  InputIterator1 idx,
  InputIterator2 value,
  Size2 n_bucket,
  OutputIterator1 prefix_bucket,
  OutputIterator2 cnt_bucket,
  OutputIterator3 value_sum_bucket,	
  const T &null_value
){
  thrust::pair<OutputIterator2, OutputIterator3> end;

  end = thrust::reduce_by_key(
    idx,
    thrusting::advance(n_value, idx),
    value,
    cnt_bucket, 
    value_sum_bucket);   

  Size2 n_non_empty = end.first - cnt_bucket;

  // wrong
  thrust::scatter(
    value_sum_bucket,
    thrusting::advance(n_non_empty, value_sum_bucket),
    cnt_bucket,
    value_sum_bucket);

  thrusting::bucket_indexing(
    n_value,
    idx,
    n_bucket,
    prefix_bucket,
    cnt_bucket);

  typedef typename thrust::iterator_value<OutputIterator2>::type Count2;
  thrust::transform_if(
    value_sum_bucket,
    thrusting::advance(n_bucket, value_sum_bucket),
    cnt_bucket, // stencil
    value_sum_bucket, // result
    thrusting::constant(null_value), // op return null_value if stencil elem is 0
    thrusting::bind2nd(thrust::equal_to<Count2>(), Count2(0)));
}

} // END thrusting
