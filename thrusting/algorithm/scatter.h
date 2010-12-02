#pragma once

/*
  in-placeable scatter algorithm
*/

#include <thrust/iterator/iterator_traits.h>
#include <thrust/scatter.h>
#include <thrust/copy.h>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

namespace thrusting {

namespace detail {

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void scatter(
  InputIterator1 first,
  InputIterator1 last,
  InputIterator2 map,
  OutputIterator output,
  thrust::host_space_tag
){
  typedef typename thrust::iterator_value<OutputIterator>::type OutputType;
  thrust::host_vector<OutputType> value_copy(first, last);
  thrust::scatter(value_copy.begin(), value_copy.end(), map, output);
}

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void scatter(
  InputIterator1 first,
  InputIterator1 last,
  InputIterator2 map,
  OutputIterator output,
  thrust::device_space_tag
){
  typedef typename thrust::iterator_value<OutputIterator>::type OutputType;
  thrust::device_vector<OutputType> value_copy(first, last);
  thrust::scatter(value_copy.begin(), value_copy.end(), map, output);
}

} // END detail

template<
typename InputIterator1,
typename InputIterator2,
typename OutputIterator>
void scatter(
  InputIterator1 first,
  InputIterator1 last,
  InputIterator2 map,
  OutputIterator output
){
  if(first==output){
    std::cout << "inplace" << std::endl;
    detail::scatter(
      first, last, map, output, 
      typename thrust::iterator_space<OutputIterator>::type());
  } else {
    std::cout << "default" << std::endl;
    thrust::scatter(first, last, map, output);
  }
}

} // END thrusting
