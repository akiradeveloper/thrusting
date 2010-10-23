#pragma once

#include <thrust/functional.h>

namespace thrusting {

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

template<typename A, typename B, typename C>
struct multiplies_a_b_c :public thrust::binary_function<A, B, C> {
  __host__ __device__
  C operator()(const A &x, const B &y){
    return x * y;
  }
};

template<typename A, typename B>
struct multiplies_a_b_a :public multiplies_a_b_c<A, B, A> {};

template<typename A, typename B, typename C>
struct divides_a_b_c :public thrust::binary_function<A, B, C> {
  __host__ __device__
  C operator()(const A &x, const B &y){
    return x / y;
  }
};

template<typename A, typename B>
struct divides_a_b_a :public divides_a_b_c<A, B, A> {};

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
