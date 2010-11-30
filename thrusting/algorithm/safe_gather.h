#pragma once

#include <thrust/iterator/iterator_traits.h>
#include <thrust/gather.h>
#include <thrust/copy.h>

namespace thrusting {

namespace detail {

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void safe_gather(
  InputIterator1 map_first,
  InputIterator1 map_last,
  InputIterator2 input,
  OutputIterator output,
  thrust::host_space_tag
){
  typedef typename thrust::iterator_value<OutputIterator>::type OutputType;
  thrust::host_vector<OutputType> output_tmp(map_last - map_first); // this code is not the best portable.
  thrust::gather(map_first, map_last, input, output_tmp.begin());
  thrust::copy(output_tmp.begin(), output_tmp.end(), output);
}

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void safe_gather(
  InputIterator1 map_first,
  InputIterator1 map_last,
  InputIterator2 input,
  OutputIterator output,
  thrust::device_space_tag
){
  thrust::gather(map_first, map_last, input, output);
}

} // END detail

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void safe_gather(
  InputIterator1 map_first,
  InputIterator1 map_last,
  InputIterator2 input,
  OutputIterator output
){
  detail::safe_gather(
    map_first, map_last, input, output, 
    typename thrust::iterator_space<OutputIterator>::type());
}

} // END thrusting
