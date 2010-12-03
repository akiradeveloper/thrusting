#include <thrust/random.h>

#include <climits>

namespace thrusting {

namespace detail {
  
__host__ __device__
unsigned int hash(unsigned int a)
{
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
typename Engine>
class hash_engine_generator :public thrust::unary_function<Idx, Engine> {
__host__ __device__
Engine operator()(Idx idx) const {
  unsigned int seed =  detail::hash(idx) % UINT_MAX;
  return Engine(seed);
}
};

template<
typename Idx,
typename Engine = thrust::default_random_engine>
hash_engine_generator<Idx, Engine> make_hash_engine_generator(){
  return hash_engine_generator();
}
}

template<
typename Idx,
typename Engine,
typename Seed>
class discard_engine_generator :public thrust::unary_function<Idx, Engine> {
  Seed _seed;
  discard_engine_generator(Seed seed)
  :_seed(seed){}
  
  __device__ __host__
  Engine operator()(Idx idx) const {
    Engine rng(_seed);
    rng.discard(idx);
    return rng;
  }
}
};

template<
typename Idx,
typename Engine = thrust::default_random_engine,
typename Seed = unsigned long long>
discard_engine_generator<Idx, Engine> make_discard_engine_generator(Seed seed){
  return discard_engine_generator(seed);
}

} // END thrusting
