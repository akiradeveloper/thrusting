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
  thrust::uniform_real_distribution<RealType> _dist;
public:
  uniform_real_distribution(RealType min, RealType max)
  :_dist(min, max){}
  /* 
    This function can not be const.
    But that is not a big problem per se.
  */
  __host__ __device__
  RealType operator()(Engine &engine){
    return _dist(engine);
  } 
};

template<
typename IntType,
typename Engine = thrust::default_random_engine>
class uniform_int_distribution :public thrust::unary_function<Engine, IntType> {
  thrust::uniform_int_distribution<IntType> _dist;
public:
  uniform_int_distribution(IntType min, IntType max)
  :_dist(min, max){}

  __host__ __device__
  IntType operator()(Engine &engine){
    return _dist(engine);
  } 
};

} // END thrusting
