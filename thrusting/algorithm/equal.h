#pragma once

#include <thrust/equal.h>

#include <thrusting/iterator.h>

namespace thrusting {

template<
typename Size,
typename InputIterator1,
typename InputIterator2,
typename BinaryPredicate>
bool equal(
  Size n,
  InputIterator1 one,
  InputIterator2 another,
  BinaryPredicate pred
){
  return thrust::equal(
    one,
    thrusting::advance(n, one),
    another,
    pred);
}

} // END thrusting
