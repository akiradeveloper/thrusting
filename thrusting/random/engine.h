#pragma once

#include <thrust/random.h>
#include <thrust/functional.h>

#include <climits>

namespace thrusting {

namespace detail {
/*
  This hash implementation is copied
  from monte-carlo example code of Thrust Library v-1.3.0
*/
__host__ __device__
unsigned int hash(unsigned int a){
  a = (a+0x7ed55d16) + (a<<12);
  a = (a^0xc761c23c) ^ (a>>19);
  a = (a+0x165667b1) + (a<<5);
  a = (a+0xd3a2646c) ^ (a<<9);
  a = (a+0xfd7046c5) + (a<<3);
  a = (a^0xb55a4f09) ^ (a>>16);
  return a;
}
} // END detail

template<
typename Idx,
typename Engine = thrust::default_random_engine>
class fast_rng_generator :public thrust::unary_function<Idx, Engine> {
public:
  __host__ __device__
  Engine operator()(Idx idx) const {
    unsigned int x = idx % UINT_MAX;
    unsigned int seed =  detail::hash(x);
    return Engine(seed);
  }
};

template<typename Idx>
fast_rng_generator<Idx> make_fast_rng_generator(){
  return fast_rng_generator<Idx>();
}

template<
typename Idx,
typename Seed,
typename Engine = thrust::default_random_engine>
class rng_generator :public thrust::unary_function<Idx, Engine> {
  Seed _seed;
public:
  rng_generator(Seed seed)
  :_seed(seed){}
  __host__ __device__
  Engine operator()(Idx idx) const {
    Engine rng(_seed);
    rng.discard(idx);
    return rng;
  }
};

template<
typename Idx,
typename Seed>
rng_generator<Idx, Seed> make_rng_generator(Seed seed){
  return rng_generator<Idx, Seed>(seed);
}

} // END thrusting
