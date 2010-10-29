#pragma once

#include <thrust/functional.h>

namespace thrusting {

template<typename A, typename B, typename C>
struct uncurry :public thrust::unary_function<thrust::tuple<A, B>, C>
  thrust::binary_function<A, B, C> _f;
  uncurry(thrust::binary_function<A, B, C> f){
    _f = f;
  }  
  C operator()(thrust::tuple<A, B> t){
    return _f(thrust::get<0>(t), thrust::get<1>(t));
  }
};

template<typename A, typename B, typename C>
struct compose :public thrust::unary_function<A, C> {
  thrust::unary_function<A, B> first;
  thrust::unary_function<B, C> second;
  compose(
    thrust::unary_function<A, B> first_,
    thrust::unary_function<B, C> second_)
  :first(first_), second(second_){}
  __host__ __device__
  C operator()(const A &x){
    return second(first(x));
  }
};

template<typename A, typename B>
struct multiplies_a_b :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y){
    return x * y;
  }
};

template<typename A, typename B>
struct divides_a_b :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y){
    return x / y;
  }
};

template<typename A, typename B>
struct left_shift :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y){
    return x << y;
  }
};

template<typename A, typename B>
struct right_shift :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y){
    return x >> y;
  }
};

} // end thrusting
