
#pragma once
#include "make_tuple_n.h"
#include "tuple_n_typedef.h"
namespace thrusting {


template<typename T>
__host__ __device__
typename tuple2<T>::type operator*(const typename tuple2<T>::type &x, const T &y){
  return make_tuple2<T>(
thrust::get<0>(x)
*y, 
thrust::get<1>(x)
*y);
}

template<typename T>
__host__ __device__
typename tuple2<T>::type operator*(const T &n, const typename tuple2<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple2<T>::type operator/(const typename tuple2<T>::type &x, const T &y){
  return make_tuple2<T>(
thrust::get<0>(x)
/y, 
thrust::get<1>(x)
/y);
}



template<typename T>
__host__ __device__
typename tuple3<T>::type operator*(const typename tuple3<T>::type &x, const T &y){
  return make_tuple3<T>(
thrust::get<0>(x)
*y, 
thrust::get<1>(x)
*y, 
thrust::get<2>(x)
*y);
}

template<typename T>
__host__ __device__
typename tuple3<T>::type operator*(const T &n, const typename tuple3<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple3<T>::type operator/(const typename tuple3<T>::type &x, const T &y){
  return make_tuple3<T>(
thrust::get<0>(x)
/y, 
thrust::get<1>(x)
/y, 
thrust::get<2>(x)
/y);
}



template<typename T>
__host__ __device__
typename tuple4<T>::type operator*(const typename tuple4<T>::type &x, const T &y){
  return make_tuple4<T>(
thrust::get<0>(x)
*y, 
thrust::get<1>(x)
*y, 
thrust::get<2>(x)
*y, 
thrust::get<3>(x)
*y);
}

template<typename T>
__host__ __device__
typename tuple4<T>::type operator*(const T &n, const typename tuple4<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple4<T>::type operator/(const typename tuple4<T>::type &x, const T &y){
  return make_tuple4<T>(
thrust::get<0>(x)
/y, 
thrust::get<1>(x)
/y, 
thrust::get<2>(x)
/y, 
thrust::get<3>(x)
/y);
}



template<typename T>
__host__ __device__
typename tuple5<T>::type operator*(const typename tuple5<T>::type &x, const T &y){
  return make_tuple5<T>(
thrust::get<0>(x)
*y, 
thrust::get<1>(x)
*y, 
thrust::get<2>(x)
*y, 
thrust::get<3>(x)
*y, 
thrust::get<4>(x)
*y);
}

template<typename T>
__host__ __device__
typename tuple5<T>::type operator*(const T &n, const typename tuple5<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple5<T>::type operator/(const typename tuple5<T>::type &x, const T &y){
  return make_tuple5<T>(
thrust::get<0>(x)
/y, 
thrust::get<1>(x)
/y, 
thrust::get<2>(x)
/y, 
thrust::get<3>(x)
/y, 
thrust::get<4>(x)
/y);
}



template<typename T>
__host__ __device__
typename tuple6<T>::type operator*(const typename tuple6<T>::type &x, const T &y){
  return make_tuple6<T>(
thrust::get<0>(x)
*y, 
thrust::get<1>(x)
*y, 
thrust::get<2>(x)
*y, 
thrust::get<3>(x)
*y, 
thrust::get<4>(x)
*y, 
thrust::get<5>(x)
*y);
}

template<typename T>
__host__ __device__
typename tuple6<T>::type operator*(const T &n, const typename tuple6<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple6<T>::type operator/(const typename tuple6<T>::type &x, const T &y){
  return make_tuple6<T>(
thrust::get<0>(x)
/y, 
thrust::get<1>(x)
/y, 
thrust::get<2>(x)
/y, 
thrust::get<3>(x)
/y, 
thrust::get<4>(x)
/y, 
thrust::get<5>(x)
/y);
}



template<typename T>
__host__ __device__
typename tuple7<T>::type operator*(const typename tuple7<T>::type &x, const T &y){
  return make_tuple7<T>(
thrust::get<0>(x)
*y, 
thrust::get<1>(x)
*y, 
thrust::get<2>(x)
*y, 
thrust::get<3>(x)
*y, 
thrust::get<4>(x)
*y, 
thrust::get<5>(x)
*y, 
thrust::get<6>(x)
*y);
}

template<typename T>
__host__ __device__
typename tuple7<T>::type operator*(const T &n, const typename tuple7<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple7<T>::type operator/(const typename tuple7<T>::type &x, const T &y){
  return make_tuple7<T>(
thrust::get<0>(x)
/y, 
thrust::get<1>(x)
/y, 
thrust::get<2>(x)
/y, 
thrust::get<3>(x)
/y, 
thrust::get<4>(x)
/y, 
thrust::get<5>(x)
/y, 
thrust::get<6>(x)
/y);
}



template<typename T>
__host__ __device__
typename tuple8<T>::type operator*(const typename tuple8<T>::type &x, const T &y){
  return make_tuple8<T>(
thrust::get<0>(x)
*y, 
thrust::get<1>(x)
*y, 
thrust::get<2>(x)
*y, 
thrust::get<3>(x)
*y, 
thrust::get<4>(x)
*y, 
thrust::get<5>(x)
*y, 
thrust::get<6>(x)
*y, 
thrust::get<7>(x)
*y);
}

template<typename T>
__host__ __device__
typename tuple8<T>::type operator*(const T &n, const typename tuple8<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple8<T>::type operator/(const typename tuple8<T>::type &x, const T &y){
  return make_tuple8<T>(
thrust::get<0>(x)
/y, 
thrust::get<1>(x)
/y, 
thrust::get<2>(x)
/y, 
thrust::get<3>(x)
/y, 
thrust::get<4>(x)
/y, 
thrust::get<5>(x)
/y, 
thrust::get<6>(x)
/y, 
thrust::get<7>(x)
/y);
}



template<typename T>
__host__ __device__
typename tuple9<T>::type operator*(const typename tuple9<T>::type &x, const T &y){
  return make_tuple9<T>(
thrust::get<0>(x)
*y, 
thrust::get<1>(x)
*y, 
thrust::get<2>(x)
*y, 
thrust::get<3>(x)
*y, 
thrust::get<4>(x)
*y, 
thrust::get<5>(x)
*y, 
thrust::get<6>(x)
*y, 
thrust::get<7>(x)
*y, 
thrust::get<8>(x)
*y);
}

template<typename T>
__host__ __device__
typename tuple9<T>::type operator*(const T &n, const typename tuple9<T>::type &x){
  return x * n;
}

template<typename T>
__host__ __device__
typename tuple9<T>::type operator/(const typename tuple9<T>::type &x, const T &y){
  return make_tuple9<T>(
thrust::get<0>(x)
/y, 
thrust::get<1>(x)
/y, 
thrust::get<2>(x)
/y, 
thrust::get<3>(x)
/y, 
thrust::get<4>(x)
/y, 
thrust::get<5>(x)
/y, 
thrust::get<6>(x)
/y, 
thrust::get<7>(x)
/y, 
thrust::get<8>(x)
/y);
}

 
}
