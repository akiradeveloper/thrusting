
#pragma once
namespace thrusting {

void operator+=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::plus<VALUE_TYPE>());
}

void operator-=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::minus<VALUE_TYPE>());
}

void operator*=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::multiplies<VALUE_TYPE>());
}

void operator/=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::divides<VALUE_TYPE>());
}

void operator%=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::modulus<VALUE_TYPE>());
}

void operator&=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::bit_and<VALUE_TYPE>());
}

void operator|=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::bit_or<VALUE_TYPE>());
}

void operator^=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  thrust::transform(head, head+n, ys, head, thrust::bit_xor<VALUE_TYPE>());
}

}
