#pragma once

/*
  in-placable scatter
*/

#include <thrust/iterator/iterator_traits.h>
#include <thrust/gather.h>
#include <thrust/copy.h>

namespace thrusting {

namespace detail {

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void gather(
  InputIterator1 map_first,
  InputIterator1 map_last,
  InputIterator2 input,
  OutputIterator output,
  thrust::host_space_tag
){
  typedef typename thrust::iterator_value<OutputIterator>::type OutputType;
  thrust::host_vector<OutputType> value_copy(
    input, 
    thrusting::advance(map_last-map_first, input));
  thrust::gather(map_first, map_last, value_copy.begin(), output);
}

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void gather(
  InputIterator1 map_first,
  InputIterator1 map_last,
  InputIterator2 input,
  OutputIterator output,
  thrust::device_space_tag
){
  typedef typename thrust::iterator_value<OutputIterator>::type OutputType;
  thrust::device_vector<OutputType> value_copy(
    input, 
    thrusting::advance(map_last-map_first, input));
  thrust::gather(map_first, map_last, value_copy.begin(), output);
}

} // END detail

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void gather(
  InputIterator1 map_first,
  InputIterator1 map_last,
  InputIterator2 input,
  OutputIterator output
){
  if(input==output){
    std::cout << "inplace" << std::endl;
    detail::gather(
      map_first, map_last, input, output, 
      typename thrust::iterator_space<OutputIterator>::type());
  } else {
    std::cout << "default" << std::endl;
    thrust::gather(map_first, map_last, input, output);
  } 
}

} // END thrusting
