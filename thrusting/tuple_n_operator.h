
#include "make_tuple_n.h"
#include "tuple_n_typedef.h"
#pragma once
namespace thrusting {


template<typename T>
__host__ __device__
typename tuple2<T>::type operator*(const typename tuple2<T>::type &x, T y){
  return make_tuple2<T>(x.get(0)*y, x.get(1)*y);
}

template<typename T>
__host__ __device__
typename tuple2<T>::type operator*(T n, const typename tuple2<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple2<T>::type operator/(const typename tuple2<T>::type &x, T y){
  return make_tuple2<T>(x.get(0)/y, x.get(1)/y);
}



template<typename T>
__host__ __device__
typename tuple3<T>::type operator*(const typename tuple3<T>::type &x, T y){
  return make_tuple3<T>(x.get(0)*y, x.get(1)*y, x.get(2)*y);
}

template<typename T>
__host__ __device__
typename tuple3<T>::type operator*(T n, const typename tuple3<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple3<T>::type operator/(const typename tuple3<T>::type &x, T y){
  return make_tuple3<T>(x.get(0)/y, x.get(1)/y, x.get(2)/y);
}



template<typename T>
__host__ __device__
typename tuple4<T>::type operator*(const typename tuple4<T>::type &x, T y){
  return make_tuple4<T>(x.get(0)*y, x.get(1)*y, x.get(2)*y, x.get(3)*y);
}

template<typename T>
__host__ __device__
typename tuple4<T>::type operator*(T n, const typename tuple4<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple4<T>::type operator/(const typename tuple4<T>::type &x, T y){
  return make_tuple4<T>(x.get(0)/y, x.get(1)/y, x.get(2)/y, x.get(3)/y);
}



template<typename T>
__host__ __device__
typename tuple5<T>::type operator*(const typename tuple5<T>::type &x, T y){
  return make_tuple5<T>(x.get(0)*y, x.get(1)*y, x.get(2)*y, x.get(3)*y, x.get(4)*y);
}

template<typename T>
__host__ __device__
typename tuple5<T>::type operator*(T n, const typename tuple5<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple5<T>::type operator/(const typename tuple5<T>::type &x, T y){
  return make_tuple5<T>(x.get(0)/y, x.get(1)/y, x.get(2)/y, x.get(3)/y, x.get(4)/y);
}



template<typename T>
__host__ __device__
typename tuple6<T>::type operator*(const typename tuple6<T>::type &x, T y){
  return make_tuple6<T>(x.get(0)*y, x.get(1)*y, x.get(2)*y, x.get(3)*y, x.get(4)*y, x.get(5)*y);
}

template<typename T>
__host__ __device__
typename tuple6<T>::type operator*(T n, const typename tuple6<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple6<T>::type operator/(const typename tuple6<T>::type &x, T y){
  return make_tuple6<T>(x.get(0)/y, x.get(1)/y, x.get(2)/y, x.get(3)/y, x.get(4)/y, x.get(5)/y);
}



template<typename T>
__host__ __device__
typename tuple7<T>::type operator*(const typename tuple7<T>::type &x, T y){
  return make_tuple7<T>(x.get(0)*y, x.get(1)*y, x.get(2)*y, x.get(3)*y, x.get(4)*y, x.get(5)*y, x.get(6)*y);
}

template<typename T>
__host__ __device__
typename tuple7<T>::type operator*(T n, const typename tuple7<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple7<T>::type operator/(const typename tuple7<T>::type &x, T y){
  return make_tuple7<T>(x.get(0)/y, x.get(1)/y, x.get(2)/y, x.get(3)/y, x.get(4)/y, x.get(5)/y, x.get(6)/y);
}



template<typename T>
__host__ __device__
typename tuple8<T>::type operator*(const typename tuple8<T>::type &x, T y){
  return make_tuple8<T>(x.get(0)*y, x.get(1)*y, x.get(2)*y, x.get(3)*y, x.get(4)*y, x.get(5)*y, x.get(6)*y, x.get(7)*y);
}

template<typename T>
__host__ __device__
typename tuple8<T>::type operator*(T n, const typename tuple8<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple8<T>::type operator/(const typename tuple8<T>::type &x, T y){
  return make_tuple8<T>(x.get(0)/y, x.get(1)/y, x.get(2)/y, x.get(3)/y, x.get(4)/y, x.get(5)/y, x.get(6)/y, x.get(7)/y);
}



template<typename T>
__host__ __device__
typename tuple9<T>::type operator*(const typename tuple9<T>::type &x, T y){
  return make_tuple9<T>(x.get(0)*y, x.get(1)*y, x.get(2)*y, x.get(3)*y, x.get(4)*y, x.get(5)*y, x.get(6)*y, x.get(7)*y, x.get(8)*y);
}

template<typename T>
__host__ __device__
typename tuple9<T>::type operator*(T n, const typename tuple9<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple9<T>::type operator/(const typename tuple9<T>::type &x, T y){
  return make_tuple9<T>(x.get(0)/y, x.get(1)/y, x.get(2)/y, x.get(3)/y, x.get(4)/y, x.get(5)/y, x.get(6)/y, x.get(7)/y, x.get(8)/y);
}

 
}
