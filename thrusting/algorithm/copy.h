#pragma once

#include <thrust/copy.h>

#include <thrusting/iterator.h>

namespace thrusting {

template<
typename Size,
typename InputIterator,
typename OutputIterator>
void copy(Size n, InputIterator from, OutputIterator to){
  thrust::copy(
    from,
    thrusting::advance(n, from),
    to);
}

} // END thrusting
