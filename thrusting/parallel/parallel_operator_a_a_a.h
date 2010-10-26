
#pragma once
#include <thrusting/parallel.h>
#include <thrust/iterator/iterator_traits.h>
namespace thrust {

template<typename A>
void operator+=(parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  size_t n = xs.length();
  thrust::transform(head, head+n, ys, head, thrust::plus<VALUE_TYPE>());
}

template<typename A>
void operator-=(parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  size_t n = xs.length();
  thrust::transform(head, head+n, ys, head, thrust::minus<VALUE_TYPE>());
}

template<typename A>
void operator*=(parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  size_t n = xs.length();
  thrust::transform(head, head+n, ys, head, thrust::multiplies<VALUE_TYPE>());
}

template<typename A>
void operator/=(parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  size_t n = xs.length();
  thrust::transform(head, head+n, ys, head, thrust::divides<VALUE_TYPE>());
}

template<typename A>
void operator%=(parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  size_t n = xs.length();
  thrust::transform(head, head+n, ys, head, thrust::modulus<VALUE_TYPE>());
}

template<typename A>
void operator&=(parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  size_t n = xs.length();
  thrust::transform(head, head+n, ys, head, thrust::bit_and<VALUE_TYPE>());
}

template<typename A>
void operator|=(parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  size_t n = xs.length();
  thrust::transform(head, head+n, ys, head, thrust::bit_or<VALUE_TYPE>());
}

template<typename A>
void operator^=(parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  size_t n = xs.length();
  thrust::transform(head, head+n, ys, head, thrust::bit_xor<VALUE_TYPE>());
}

}
