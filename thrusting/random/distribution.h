#pragma once

#include <thrust/functional.h>
#include <thrust/random/uniform_int_distribution.h>
#include <thrust/random/uniform_real_distribution.h>

namespace thrusting {

template<typename Engine, typename RealType>
class uniform_real_distribution :public thrust:unary_function<Engine, RealType> {
  RealType _min, _max;
  thrust::uniform_real_distribution<RealType> _dist;
public:
  uniform_real_distribution(RealType min, RealType max)
  :_min(min), _max(max), _dist(min, max){}

  template<typename Engine>
  __host__ __device__
  RealType operator()(const Engine &engine) const {
    return _dist(engine);
  } 
};

template<typename Engine, typename IntType>
class uniform_int_distribution :public thrust::unary_function<Engine, IntType> {
  IntType _min, _max;
  thrust::uniform_int_distribution<IntType> _dist;
public:
  uniform_int_distribution(IntType min, IntType max)
  :_min(min), _max(max), _dist(min, max){}

  template<typename Engine>
  __host__ __device__
  IntType operator()(const Engine &engine) const {
    return _dist(engine);
  } 
};

} // END thrusting
