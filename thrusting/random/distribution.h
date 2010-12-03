#pragma once

#include <thrust/functional.h>
#include <thrust/random.h>
#include <thrust/random/uniform_int_distribution.h>
#include <thrust/random/uniform_real_distribution.h>

namespace thrusting {

template<
typename RealType,
typename Engine = thrust::default_random_engine>
class uniform_real_distribution :public thrust::unary_function<Engine, RealType> {
  RealType _min, _max;
public:
  uniform_real_distribution(RealType min, RealType max)
  :_min(min), _max(max){}
  /* 
    This function can not be const.
    But that is not a big problem per se.
  */
  __host__ __device__
  RealType operator()(Engine &engine) const {
    thrust::uniform_real_distribution<RealType> dist(_min, _max);
    return dist(engine);
  } 
};

template<
typename IntType,
typename Engine = thrust::default_random_engine>
class uniform_int_distribution :public thrust::unary_function<Engine, IntType> {
  IntType _min, _max;
public:
  uniform_int_distribution(IntType min, IntType max)
  :_min(min), _max(max){}

  __host__ __device__
  IntType operator()(Engine &engine) const {
    thrust::uniform_int_distribution<IntType> dist(_min, _max);
    return dist(engine);
  } 
};

} // END thrusting
