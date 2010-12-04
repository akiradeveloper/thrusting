#pragma once

#include <thrust/iterator/counting_iterator.h>
#include <thrust/iterator/transform_iterator.h>
#include <thrust/copy.h>

#include <thrusting/iterator.h>

#include <thrusting/random/engine.h>
#include <thrusting/random/distribution.h>

namespace {
  using namespace thrust;
}

namespace thrusting {

/*
  RandomGenerator is Idx -> ValueType
*/
template<
typename OutputIterator,
typename RandomGenerator>
void generate(
  OutputIterator first,
  OutputIterator last,
  RandomGenerator gen
){
  thrust::copy( 
    make_transform_iterator(
      make_counting_iterator(0), gen),
    make_transform_iterator(
      make_counting_iterator(last-first), gen),
    first);
}

} // END thrusting
