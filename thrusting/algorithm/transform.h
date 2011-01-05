#pragma once

#include <thrust/transform.h>

#include <thrusting/iterator.h>

namespace thrusting {


template<
typename Size,
typename InputIterator1,
typename InputIterator2,
typename ForwardIterator,
typename UnaryFunction,
typename Predicate>
ForwardIterator transform_if(
  Size n,
  InputIterator1 first,
  InputIterator2 stencil,
  ForwardIterator result,
  UnaryFunction op,
  Predicate pred
){
  return thrust::transform_if(
    first,
    thrusting::advance(n, first),
    stencil,
    result,
    op,
    pred);
}

// not tested
template<
typename Size,
typename InputIterator,
typename OutputIterator,
typename UnaryFunction>
OutputIterator transform(
  Size n,
  InputIterator first,
  OutputIterator result,
  UnaryFunction op
){
  return thrust::transform(
    first,
    thrusting::advance(n, first),
    result,
    op);
}

transform_if_by_map(
  Size n,
  InputIterator1 first,
  InputIterator2 stencil,
  OutputIterator output,
  InputIterator3 map,
  Predicate pred
){
  return thrusting::transform_if(
    n,
    first,   
}

} // END thrusting
