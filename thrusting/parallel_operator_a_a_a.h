
#pragma once
#include "parallel.h"
namespace thrusting {

template<typename A>
void operator+=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::plus<VALUE_TYPE>());
}

template<typename A>
void operator-=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::minus<VALUE_TYPE>());
}

template<typename A>
void operator*=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::multiplies<VALUE_TYPE>());
}

template<typename A>
void operator/=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::divides<VALUE_TYPE>());
}

template<typename A>
void operator%=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::modulus<VALUE_TYPE>());
}

template<typename A>
void operator&=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::bit_and<VALUE_TYPE>());
}

template<typename A>
void operator|=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::bit_or<VALUE_TYPE>());
}

template<typename A>
void operator^=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::bit_xor<VALUE_TYPE>());
}

}
