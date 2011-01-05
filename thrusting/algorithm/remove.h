#pragma once

#include <thrusting/algorithm/advance.h>
#include <thrusting/functional.h>

#include <thrust/distance.h>
#include <thrust/remove.h>

namespace thrusting {

/*
  simple wrapper, will not tested
*/
template<
typename Size,
typename InputIterator
typename Predicate>
Size remove_if(
  Size n,
  InputIterator first,
  Predicate pred
){
  InputIterator end = remove_if(
    first,
    thrusting::advance(n, first),
    pred);

  return thrusting::distance(first, end);
}

/*
  simple wrapper
*/
template<
typename Size,
typename InputIterator1,
typename InputIterator2,
typename Predicate>
Size remove_if(
  Size n,
  InputIterator1 first,
  InputIterator2 stencil,
  Predicate pred
){
  InputIterator1 end = remove_if(
    first,
    thrusting::advance(n, first),
    stencil,
    pred);

  return thrusting::distance(first, end);
}

template<
typename Size,
typename InputIterator,
typename OutputIterator,
typename Predicate>
Size sort_out_if(
  Size n,
  InputIterator first,
  OutputIterator trashbox,
  Predicate pred
){
  InputIterator end;
  end = thrusting::partition(
    n,
    thrusting::advance(n, first),
    thrusting::compose(
      thrust::logical_not(),
      pred));        

  thrust::copy(
    end,
    thrusting::advance(n, first),
    trashbox);

  return end - first;
}

} // END thrusting
