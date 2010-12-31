#pragma once

/*
  Reduce By Bucket algorithm

  invented by Akira Hayakawa, 2010.
*/

/*
  THIS algorithm is error-prone.
  because it uses thrusting::scatter.
  DO NOT USE!!!
*/

#include <thrust/reduce.h>
#include <thrust/transform.h>
#include <thrust/iterator/iterator_traits.h>

#include <thrusting/algorithm/bucket_indexing.h>
#include <thrusting/iterator.h>
#include <thrusting/functional.h>
#include <thrusting/algorithm/scatter.h>

#include <iostream>
#include <thrust/distance.h>
#include <thrusting/list.h>

namespace thrusting {
  
/*
  Example,
  
  Input,
  indices is [1,2,2], 
  values is [3,4,5]
  and n_bucket is 4,
  implicitly n_value is 3.

  Then the Output will be
  [0,0,1,3] for prefix
  [0,1,2,0] for cnt
  [N,3,9,N] for values where N is null value.
*/
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
  OutputIterator3 tmp,
  const T &null_value
){
  thrust::pair<OutputIterator2, OutputIterator3> end;

  std::cout << "@reduce_by_bucket reduce_by_key" << std::endl;
  // std::cout << make_list(n_value, idx) << std::endl;
  // std::cout << make_list(n_bucket, cnt_bucket) << std::endl;
  end = thrust::reduce_by_key(
    idx,
    thrusting::advance(n_value, idx),
    value,
    cnt_bucket, 
    tmp);   

  Size2 n_non_empty = thrust::distance(cnt_bucket, end.first);
  std::cout << "@reduce_by_bucket aaaaa n_bucket: " << n_bucket << std::endl;
  std::cout << "@reduce_by_bucket n_non_empty: " << n_non_empty << std::endl;

  std::cout << "@reduce_by_bucket fill" << std::endl;
  thrust::fill(
    value_sum_bucket,
    thrusting::advance(n_bucket, value_sum_bucket),
    null_value);   

  std::cout << "@reduce_by_bucket scatter" << std::endl;
  // std::cout << make_list(n_bucket, cnt_bucket) << std::endl;
  thrust::scatter(
    tmp,
    thrusting::advance(n_non_empty, tmp),
    cnt_bucket,
    value_sum_bucket);

  std::cout << "@reduce_by_bucket bucket_indexing" << std::endl;
  thrusting::bucket_indexing(
    n_value,
    idx,
    n_bucket,
    prefix_bucket,
    cnt_bucket);
}

/*
  deprecated
  preserved only for testing
*/
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
  typename vector_of<OutputIterator3>::type tmp(n_bucket);
  
  reduce_by_bucket(
    n_value,
    idx,
    value,
    n_bucket,
    prefix_bucket,
    cnt_bucket,
    value_sum_bucket,
    tmp.begin(),
    null_value);
}

} // END thrusting
