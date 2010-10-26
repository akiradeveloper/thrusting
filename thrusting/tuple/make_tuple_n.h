
#pragma once
#include "tuple_n_typedef.h"
namespace thrust {

template<typename T>
__host__ __device__
typename tuple2<T>::type make_tuple2(T x0, T x1){
  return thrust::make_tuple(x0, x1);
}

template<typename T>
__host__ __device__
typename tuple3<T>::type make_tuple3(T x0, T x1, T x2){
  return thrust::make_tuple(x0, x1, x2);
}

template<typename T>
__host__ __device__
typename tuple4<T>::type make_tuple4(T x0, T x1, T x2, T x3){
  return thrust::make_tuple(x0, x1, x2, x3);
}

template<typename T>
__host__ __device__
typename tuple5<T>::type make_tuple5(T x0, T x1, T x2, T x3, T x4){
  return thrust::make_tuple(x0, x1, x2, x3, x4);
}

template<typename T>
__host__ __device__
typename tuple6<T>::type make_tuple6(T x0, T x1, T x2, T x3, T x4, T x5){
  return thrust::make_tuple(x0, x1, x2, x3, x4, x5);
}

template<typename T>
__host__ __device__
typename tuple7<T>::type make_tuple7(T x0, T x1, T x2, T x3, T x4, T x5, T x6){
  return thrust::make_tuple(x0, x1, x2, x3, x4, x5, x6);
}

template<typename T>
__host__ __device__
typename tuple8<T>::type make_tuple8(T x0, T x1, T x2, T x3, T x4, T x5, T x6, T x7){
  return thrust::make_tuple(x0, x1, x2, x3, x4, x5, x6, x7);
}

template<typename T>
__host__ __device__
typename tuple9<T>::type make_tuple9(T x0, T x1, T x2, T x3, T x4, T x5, T x6, T x7, T x8){
  return thrust::make_tuple(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
