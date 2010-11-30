#pragma once

#include <thrust/iterator/iterator_traits.h>
#include <thrust/scatter.h>
#include <thrust/copy.h>

namespace thrusting {

namespace detail {

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void safe_scatter(
  InputIterator1 first,
  InputIterator1 last,
  InputIterator2 map,
  OutputIterator output,
  thrust::host_space_tag
){
  typedef typename thrust::iterator_value<OutputIterator>::type OutputType;
  thrust::host_vector<OutputType> output_tmp(last-first); // this code is not the best portable.
  thrust::scatter(first, last, map, output_tmp.begin());
  thrust::copy(output_tmp.begin(), output_tmp.end(), output);
}

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void safe_scatter(
  InputIterator1 first,
  InputIterator1 last,
  InputIterator2 map,
  OutputIterator output,
  thrust::device_space_tag
){
  thrust::scatter(first, last, map, output);
}

} // END detail

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void safe_scatter(
  InputIterator1 first,
  InputIterator1 last,
  InputIterator2 map,
  OutputIterator output
){
  detail::safe_scatter(
    first, last, map, output, 
    typename thrust::iterator_space<OutputIterator>::type());
}

} // END thrusting
