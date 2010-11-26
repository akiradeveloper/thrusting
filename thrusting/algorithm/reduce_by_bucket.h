#include <thrust/reduce.h>
#include <thrust/fill.h>
#include <thrust/find.h>
#include <thrust/transform.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/scatter.h>

#include <thrusting/iterator.h>

namespace thrusting {
  
<template
typename Size1,
typename Size2,
typename InputIterator1,
typename InputIterator2,
typename OutputIterator1,
typename OutputIterator2,
typename T>
void reduce_by_bucket(
  Size1 n_value,
  InputIterator1 idx,
  InputIterator2 value,
  Size2 n_bucket,
  OutputIterator1 cnt_output,
  OutputIterator2 value_output,	
  OutputIterator1 cnt_output_tmp1,
  OutputIterator1 cnt_output_tmp2,
  OutputIterator2 value_output_tmp,
  const T &null_value
){
  typedef thrust::iterator_value<OutputIterator1>::type Count;
  Count sentinel(0);
  
  /*
    if not empty, the cnt is more than 0.
    finding 0 means finding the beginning of emtpy bucket.
  */
  thrust::fill(
    cnt_output_tmp1,
    thrusting::advance(n_bucket, cnt_output_tmp1),
    sentinel);

  thrust::reduce_by_key(
    idx,
    thrusting::advance(n_value, idx),
    idx,
    cnt_output_tmp1, // cnt for non_empty bucket, [a,b,...,0,0,...]
    cnt_output_tmp2); // idx*cnt for non_empty bucket [idx_a*a,idx_b*b,...,0,0,...]

  OutputIterator1 it_sentinel = thrust::find(
    cnt_output_tmp1,
    thrusting::advance(n_bucket, cnt_output_tmp1),
    sentinel);
  
  Size2 n_non_empty = it_sentinel - cnt_output_tmp1;
  
  /*
    calculate the idx*cnt / cnt in parallel.
  */
  thrust::transform(
    cnt_output_tmp2, 
    thrusting::advance(n_non_empty, cnt_output_tmp2),
    cnt_output_tmp1,
    cnt_output_tmp2, // [idx_a,idx_b,...,0,0,...]
    thrust::divides<Count>());

  /*
    putting to output,
    algorithm is common for cnt and value,
    1. initialize the output
    2. scatter the data by idx.
  */
  Count null_cnt(0);

  thrust::fill(
    cnt_output,
    thrusting::advance(n_bucket, cnt_output),
    null_cnt);   

  thrust::scatter(
    cnt_output_tmp1,
    thrusting::advance(n_non_empty, cnt_output_tmp1),
    cnt_output_tmp2,
    cnt_output);

  /*
    Output to value_output
  */
  thrust::reduce_by_key(
    idx,
    thrusting::advance(n_value, idx),
    value,
    cnt_output_tmp1, // resubstitute the same by key reducing
    value_output_tmp);   

  thrust::fill(
    value_output,
    thrusting::advance(n_bucket, value_output),
    null_value);

  thrust::scatter(
    value_output_tmp,
    thrusting::advance(n_non_empty, value_output_tmp),
    cnt_output_tmp2,
    value_output);   
}

} // END thrusting
