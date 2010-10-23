
#pragma once
#include <iostream>
#include <sstream>
namespace thrusting {

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
__host__ __device__
typename thrust::tuple<T4, T5> operator+(const thrust::tuple<T0, T1> &x, const thrust::tuple<T2, T3> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
+
thrust::get<0>(y)
, 
thrust::get<1>(x)
+
thrust::get<1>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
__host__ __device__
typename thrust::tuple<T4, T5> operator-(const thrust::tuple<T0, T1> &x, const thrust::tuple<T2, T3> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
-
thrust::get<0>(y)
, 
thrust::get<1>(x)
-
thrust::get<1>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
__host__ __device__
typename thrust::tuple<T4, T5> operator*(const thrust::tuple<T0, T1> &x, const thrust::tuple<T2, T3> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
*
thrust::get<0>(y)
, 
thrust::get<1>(x)
*
thrust::get<1>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
__host__ __device__
typename thrust::tuple<T4, T5> operator/(const thrust::tuple<T0, T1> &x, const thrust::tuple<T2, T3> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
/
thrust::get<0>(y)
, 
thrust::get<1>(x)
/
thrust::get<1>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
__host__ __device__
typename thrust::tuple<T6, T7, T8> operator+(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T3, T4, T5> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
+
thrust::get<0>(y)
, 
thrust::get<1>(x)
+
thrust::get<1>(y)
, 
thrust::get<2>(x)
+
thrust::get<2>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
__host__ __device__
typename thrust::tuple<T6, T7, T8> operator-(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T3, T4, T5> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
-
thrust::get<0>(y)
, 
thrust::get<1>(x)
-
thrust::get<1>(y)
, 
thrust::get<2>(x)
-
thrust::get<2>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
__host__ __device__
typename thrust::tuple<T6, T7, T8> operator*(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T3, T4, T5> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
*
thrust::get<0>(y)
, 
thrust::get<1>(x)
*
thrust::get<1>(y)
, 
thrust::get<2>(x)
*
thrust::get<2>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
__host__ __device__
typename thrust::tuple<T6, T7, T8> operator/(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T3, T4, T5> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
/
thrust::get<0>(y)
, 
thrust::get<1>(x)
/
thrust::get<1>(y)
, 
thrust::get<2>(x)
/
thrust::get<2>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
__host__ __device__
typename thrust::tuple<T8, T9, T10, T11> operator+(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T4, T5, T6, T7> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
+
thrust::get<0>(y)
, 
thrust::get<1>(x)
+
thrust::get<1>(y)
, 
thrust::get<2>(x)
+
thrust::get<2>(y)
, 
thrust::get<3>(x)
+
thrust::get<3>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
__host__ __device__
typename thrust::tuple<T8, T9, T10, T11> operator-(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T4, T5, T6, T7> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
-
thrust::get<0>(y)
, 
thrust::get<1>(x)
-
thrust::get<1>(y)
, 
thrust::get<2>(x)
-
thrust::get<2>(y)
, 
thrust::get<3>(x)
-
thrust::get<3>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
__host__ __device__
typename thrust::tuple<T8, T9, T10, T11> operator*(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T4, T5, T6, T7> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
*
thrust::get<0>(y)
, 
thrust::get<1>(x)
*
thrust::get<1>(y)
, 
thrust::get<2>(x)
*
thrust::get<2>(y)
, 
thrust::get<3>(x)
*
thrust::get<3>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
__host__ __device__
typename thrust::tuple<T8, T9, T10, T11> operator/(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T4, T5, T6, T7> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
/
thrust::get<0>(y)
, 
thrust::get<1>(x)
/
thrust::get<1>(y)
, 
thrust::get<2>(x)
/
thrust::get<2>(y)
, 
thrust::get<3>(x)
/
thrust::get<3>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
__host__ __device__
typename thrust::tuple<T10, T11, T12, T13, T14> operator+(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T5, T6, T7, T8, T9> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
+
thrust::get<0>(y)
, 
thrust::get<1>(x)
+
thrust::get<1>(y)
, 
thrust::get<2>(x)
+
thrust::get<2>(y)
, 
thrust::get<3>(x)
+
thrust::get<3>(y)
, 
thrust::get<4>(x)
+
thrust::get<4>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
__host__ __device__
typename thrust::tuple<T10, T11, T12, T13, T14> operator-(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T5, T6, T7, T8, T9> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
-
thrust::get<0>(y)
, 
thrust::get<1>(x)
-
thrust::get<1>(y)
, 
thrust::get<2>(x)
-
thrust::get<2>(y)
, 
thrust::get<3>(x)
-
thrust::get<3>(y)
, 
thrust::get<4>(x)
-
thrust::get<4>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
__host__ __device__
typename thrust::tuple<T10, T11, T12, T13, T14> operator*(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T5, T6, T7, T8, T9> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
*
thrust::get<0>(y)
, 
thrust::get<1>(x)
*
thrust::get<1>(y)
, 
thrust::get<2>(x)
*
thrust::get<2>(y)
, 
thrust::get<3>(x)
*
thrust::get<3>(y)
, 
thrust::get<4>(x)
*
thrust::get<4>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
__host__ __device__
typename thrust::tuple<T10, T11, T12, T13, T14> operator/(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T5, T6, T7, T8, T9> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
/
thrust::get<0>(y)
, 
thrust::get<1>(x)
/
thrust::get<1>(y)
, 
thrust::get<2>(x)
/
thrust::get<2>(y)
, 
thrust::get<3>(x)
/
thrust::get<3>(y)
, 
thrust::get<4>(x)
/
thrust::get<4>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
__host__ __device__
typename thrust::tuple<T12, T13, T14, T15, T16, T17> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T6, T7, T8, T9, T10, T11> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
+
thrust::get<0>(y)
, 
thrust::get<1>(x)
+
thrust::get<1>(y)
, 
thrust::get<2>(x)
+
thrust::get<2>(y)
, 
thrust::get<3>(x)
+
thrust::get<3>(y)
, 
thrust::get<4>(x)
+
thrust::get<4>(y)
, 
thrust::get<5>(x)
+
thrust::get<5>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
__host__ __device__
typename thrust::tuple<T12, T13, T14, T15, T16, T17> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T6, T7, T8, T9, T10, T11> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
-
thrust::get<0>(y)
, 
thrust::get<1>(x)
-
thrust::get<1>(y)
, 
thrust::get<2>(x)
-
thrust::get<2>(y)
, 
thrust::get<3>(x)
-
thrust::get<3>(y)
, 
thrust::get<4>(x)
-
thrust::get<4>(y)
, 
thrust::get<5>(x)
-
thrust::get<5>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
__host__ __device__
typename thrust::tuple<T12, T13, T14, T15, T16, T17> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T6, T7, T8, T9, T10, T11> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
*
thrust::get<0>(y)
, 
thrust::get<1>(x)
*
thrust::get<1>(y)
, 
thrust::get<2>(x)
*
thrust::get<2>(y)
, 
thrust::get<3>(x)
*
thrust::get<3>(y)
, 
thrust::get<4>(x)
*
thrust::get<4>(y)
, 
thrust::get<5>(x)
*
thrust::get<5>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
__host__ __device__
typename thrust::tuple<T12, T13, T14, T15, T16, T17> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T6, T7, T8, T9, T10, T11> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
/
thrust::get<0>(y)
, 
thrust::get<1>(x)
/
thrust::get<1>(y)
, 
thrust::get<2>(x)
/
thrust::get<2>(y)
, 
thrust::get<3>(x)
/
thrust::get<3>(y)
, 
thrust::get<4>(x)
/
thrust::get<4>(y)
, 
thrust::get<5>(x)
/
thrust::get<5>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
__host__ __device__
typename thrust::tuple<T14, T15, T16, T17, T18, T19, T20> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T7, T8, T9, T10, T11, T12, T13> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
+
thrust::get<0>(y)
, 
thrust::get<1>(x)
+
thrust::get<1>(y)
, 
thrust::get<2>(x)
+
thrust::get<2>(y)
, 
thrust::get<3>(x)
+
thrust::get<3>(y)
, 
thrust::get<4>(x)
+
thrust::get<4>(y)
, 
thrust::get<5>(x)
+
thrust::get<5>(y)
, 
thrust::get<6>(x)
+
thrust::get<6>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
__host__ __device__
typename thrust::tuple<T14, T15, T16, T17, T18, T19, T20> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T7, T8, T9, T10, T11, T12, T13> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
-
thrust::get<0>(y)
, 
thrust::get<1>(x)
-
thrust::get<1>(y)
, 
thrust::get<2>(x)
-
thrust::get<2>(y)
, 
thrust::get<3>(x)
-
thrust::get<3>(y)
, 
thrust::get<4>(x)
-
thrust::get<4>(y)
, 
thrust::get<5>(x)
-
thrust::get<5>(y)
, 
thrust::get<6>(x)
-
thrust::get<6>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
__host__ __device__
typename thrust::tuple<T14, T15, T16, T17, T18, T19, T20> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T7, T8, T9, T10, T11, T12, T13> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
*
thrust::get<0>(y)
, 
thrust::get<1>(x)
*
thrust::get<1>(y)
, 
thrust::get<2>(x)
*
thrust::get<2>(y)
, 
thrust::get<3>(x)
*
thrust::get<3>(y)
, 
thrust::get<4>(x)
*
thrust::get<4>(y)
, 
thrust::get<5>(x)
*
thrust::get<5>(y)
, 
thrust::get<6>(x)
*
thrust::get<6>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
__host__ __device__
typename thrust::tuple<T14, T15, T16, T17, T18, T19, T20> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T7, T8, T9, T10, T11, T12, T13> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
/
thrust::get<0>(y)
, 
thrust::get<1>(x)
/
thrust::get<1>(y)
, 
thrust::get<2>(x)
/
thrust::get<2>(y)
, 
thrust::get<3>(x)
/
thrust::get<3>(y)
, 
thrust::get<4>(x)
/
thrust::get<4>(y)
, 
thrust::get<5>(x)
/
thrust::get<5>(y)
, 
thrust::get<6>(x)
/
thrust::get<6>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23>
__host__ __device__
typename thrust::tuple<T16, T17, T18, T19, T20, T21, T22, T23> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T8, T9, T10, T11, T12, T13, T14, T15> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
+
thrust::get<0>(y)
, 
thrust::get<1>(x)
+
thrust::get<1>(y)
, 
thrust::get<2>(x)
+
thrust::get<2>(y)
, 
thrust::get<3>(x)
+
thrust::get<3>(y)
, 
thrust::get<4>(x)
+
thrust::get<4>(y)
, 
thrust::get<5>(x)
+
thrust::get<5>(y)
, 
thrust::get<6>(x)
+
thrust::get<6>(y)
, 
thrust::get<7>(x)
+
thrust::get<7>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23>
__host__ __device__
typename thrust::tuple<T16, T17, T18, T19, T20, T21, T22, T23> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T8, T9, T10, T11, T12, T13, T14, T15> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
-
thrust::get<0>(y)
, 
thrust::get<1>(x)
-
thrust::get<1>(y)
, 
thrust::get<2>(x)
-
thrust::get<2>(y)
, 
thrust::get<3>(x)
-
thrust::get<3>(y)
, 
thrust::get<4>(x)
-
thrust::get<4>(y)
, 
thrust::get<5>(x)
-
thrust::get<5>(y)
, 
thrust::get<6>(x)
-
thrust::get<6>(y)
, 
thrust::get<7>(x)
-
thrust::get<7>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23>
__host__ __device__
typename thrust::tuple<T16, T17, T18, T19, T20, T21, T22, T23> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T8, T9, T10, T11, T12, T13, T14, T15> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
*
thrust::get<0>(y)
, 
thrust::get<1>(x)
*
thrust::get<1>(y)
, 
thrust::get<2>(x)
*
thrust::get<2>(y)
, 
thrust::get<3>(x)
*
thrust::get<3>(y)
, 
thrust::get<4>(x)
*
thrust::get<4>(y)
, 
thrust::get<5>(x)
*
thrust::get<5>(y)
, 
thrust::get<6>(x)
*
thrust::get<6>(y)
, 
thrust::get<7>(x)
*
thrust::get<7>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23>
__host__ __device__
typename thrust::tuple<T16, T17, T18, T19, T20, T21, T22, T23> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T8, T9, T10, T11, T12, T13, T14, T15> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
/
thrust::get<0>(y)
, 
thrust::get<1>(x)
/
thrust::get<1>(y)
, 
thrust::get<2>(x)
/
thrust::get<2>(y)
, 
thrust::get<3>(x)
/
thrust::get<3>(y)
, 
thrust::get<4>(x)
/
thrust::get<4>(y)
, 
thrust::get<5>(x)
/
thrust::get<5>(y)
, 
thrust::get<6>(x)
/
thrust::get<6>(y)
, 
thrust::get<7>(x)
/
thrust::get<7>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26>
__host__ __device__
typename thrust::tuple<T18, T19, T20, T21, T22, T23, T24, T25, T26> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T9, T10, T11, T12, T13, T14, T15, T16, T17> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
+
thrust::get<0>(y)
, 
thrust::get<1>(x)
+
thrust::get<1>(y)
, 
thrust::get<2>(x)
+
thrust::get<2>(y)
, 
thrust::get<3>(x)
+
thrust::get<3>(y)
, 
thrust::get<4>(x)
+
thrust::get<4>(y)
, 
thrust::get<5>(x)
+
thrust::get<5>(y)
, 
thrust::get<6>(x)
+
thrust::get<6>(y)
, 
thrust::get<7>(x)
+
thrust::get<7>(y)
, 
thrust::get<8>(x)
+
thrust::get<8>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26>
__host__ __device__
typename thrust::tuple<T18, T19, T20, T21, T22, T23, T24, T25, T26> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T9, T10, T11, T12, T13, T14, T15, T16, T17> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
-
thrust::get<0>(y)
, 
thrust::get<1>(x)
-
thrust::get<1>(y)
, 
thrust::get<2>(x)
-
thrust::get<2>(y)
, 
thrust::get<3>(x)
-
thrust::get<3>(y)
, 
thrust::get<4>(x)
-
thrust::get<4>(y)
, 
thrust::get<5>(x)
-
thrust::get<5>(y)
, 
thrust::get<6>(x)
-
thrust::get<6>(y)
, 
thrust::get<7>(x)
-
thrust::get<7>(y)
, 
thrust::get<8>(x)
-
thrust::get<8>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26>
__host__ __device__
typename thrust::tuple<T18, T19, T20, T21, T22, T23, T24, T25, T26> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T9, T10, T11, T12, T13, T14, T15, T16, T17> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
*
thrust::get<0>(y)
, 
thrust::get<1>(x)
*
thrust::get<1>(y)
, 
thrust::get<2>(x)
*
thrust::get<2>(y)
, 
thrust::get<3>(x)
*
thrust::get<3>(y)
, 
thrust::get<4>(x)
*
thrust::get<4>(y)
, 
thrust::get<5>(x)
*
thrust::get<5>(y)
, 
thrust::get<6>(x)
*
thrust::get<6>(y)
, 
thrust::get<7>(x)
*
thrust::get<7>(y)
, 
thrust::get<8>(x)
*
thrust::get<8>(y)
);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26>
__host__ __device__
typename thrust::tuple<T18, T19, T20, T21, T22, T23, T24, T25, T26> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T9, T10, T11, T12, T13, T14, T15, T16, T17> &y){
  return thrust::make_tuple(
thrust::get<0>(x)
/
thrust::get<0>(y)
, 
thrust::get<1>(x)
/
thrust::get<1>(y)
, 
thrust::get<2>(x)
/
thrust::get<2>(y)
, 
thrust::get<3>(x)
/
thrust::get<3>(y)
, 
thrust::get<4>(x)
/
thrust::get<4>(y)
, 
thrust::get<5>(x)
/
thrust::get<5>(y)
, 
thrust::get<6>(x)
/
thrust::get<6>(y)
, 
thrust::get<7>(x)
/
thrust::get<7>(y)
, 
thrust::get<8>(x)
/
thrust::get<8>(y)
);
}


template<typename T0, typename T1>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<T0, T1> &x){
  std::stringstream ss;
  ss << "(" << 
thrust::get<0>(x)
 << ", " << 
thrust::get<1>(x)
 << ")";
  os << ss.str();
  return os;
}

template<typename T0, typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<T0, T1, T2> &x){
  std::stringstream ss;
  ss << "(" << 
thrust::get<0>(x)
 << ", " << 
thrust::get<1>(x)
 << ", " << 
thrust::get<2>(x)
 << ")";
  os << ss.str();
  return os;
}

template<typename T0, typename T1, typename T2, typename T3>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<T0, T1, T2, T3> &x){
  std::stringstream ss;
  ss << "(" << 
thrust::get<0>(x)
 << ", " << 
thrust::get<1>(x)
 << ", " << 
thrust::get<2>(x)
 << ", " << 
thrust::get<3>(x)
 << ")";
  os << ss.str();
  return os;
}

template<typename T0, typename T1, typename T2, typename T3, typename T4>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<T0, T1, T2, T3, T4> &x){
  std::stringstream ss;
  ss << "(" << 
thrust::get<0>(x)
 << ", " << 
thrust::get<1>(x)
 << ", " << 
thrust::get<2>(x)
 << ", " << 
thrust::get<3>(x)
 << ", " << 
thrust::get<4>(x)
 << ")";
  os << ss.str();
  return os;
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<T0, T1, T2, T3, T4, T5> &x){
  std::stringstream ss;
  ss << "(" << 
thrust::get<0>(x)
 << ", " << 
thrust::get<1>(x)
 << ", " << 
thrust::get<2>(x)
 << ", " << 
thrust::get<3>(x)
 << ", " << 
thrust::get<4>(x)
 << ", " << 
thrust::get<5>(x)
 << ")";
  os << ss.str();
  return os;
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x){
  std::stringstream ss;
  ss << "(" << 
thrust::get<0>(x)
 << ", " << 
thrust::get<1>(x)
 << ", " << 
thrust::get<2>(x)
 << ", " << 
thrust::get<3>(x)
 << ", " << 
thrust::get<4>(x)
 << ", " << 
thrust::get<5>(x)
 << ", " << 
thrust::get<6>(x)
 << ")";
  os << ss.str();
  return os;
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x){
  std::stringstream ss;
  ss << "(" << 
thrust::get<0>(x)
 << ", " << 
thrust::get<1>(x)
 << ", " << 
thrust::get<2>(x)
 << ", " << 
thrust::get<3>(x)
 << ", " << 
thrust::get<4>(x)
 << ", " << 
thrust::get<5>(x)
 << ", " << 
thrust::get<6>(x)
 << ", " << 
thrust::get<7>(x)
 << ")";
  os << ss.str();
  return os;
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x){
  std::stringstream ss;
  ss << "(" << 
thrust::get<0>(x)
 << ", " << 
thrust::get<1>(x)
 << ", " << 
thrust::get<2>(x)
 << ", " << 
thrust::get<3>(x)
 << ", " << 
thrust::get<4>(x)
 << ", " << 
thrust::get<5>(x)
 << ", " << 
thrust::get<6>(x)
 << ", " << 
thrust::get<7>(x)
 << ", " << 
thrust::get<8>(x)
 << ")";
  os << ss.str();
  return os;
}


template<typename T0, typename T1>
__host__ __device__
bool operator==(const thrust::tuple<T0, T1> &x, const thrust::tuple<T0, T1> &y){
  return (
thrust::get<0>(x)
 == 
thrust::get<0>(y)
) && (
thrust::get<1>(x)
 == 
thrust::get<1>(y)
);
}
template<typename T0, typename T1>
__host__ __device__
bool operator!=(const thrust::tuple<T0, T1> &x, const thrust::tuple<T0, T1> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2>
__host__ __device__
bool operator==(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T0, T1, T2> &y){
  return (
thrust::get<0>(x)
 == 
thrust::get<0>(y)
) && (
thrust::get<1>(x)
 == 
thrust::get<1>(y)
) && (
thrust::get<2>(x)
 == 
thrust::get<2>(y)
);
}
template<typename T0, typename T1, typename T2>
__host__ __device__
bool operator!=(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T0, T1, T2> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3>
__host__ __device__
bool operator==(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T0, T1, T2, T3> &y){
  return (
thrust::get<0>(x)
 == 
thrust::get<0>(y)
) && (
thrust::get<1>(x)
 == 
thrust::get<1>(y)
) && (
thrust::get<2>(x)
 == 
thrust::get<2>(y)
) && (
thrust::get<3>(x)
 == 
thrust::get<3>(y)
);
}
template<typename T0, typename T1, typename T2, typename T3>
__host__ __device__
bool operator!=(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T0, T1, T2, T3> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4>
__host__ __device__
bool operator==(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T0, T1, T2, T3, T4> &y){
  return (
thrust::get<0>(x)
 == 
thrust::get<0>(y)
) && (
thrust::get<1>(x)
 == 
thrust::get<1>(y)
) && (
thrust::get<2>(x)
 == 
thrust::get<2>(y)
) && (
thrust::get<3>(x)
 == 
thrust::get<3>(y)
) && (
thrust::get<4>(x)
 == 
thrust::get<4>(y)
);
}
template<typename T0, typename T1, typename T2, typename T3, typename T4>
__host__ __device__
bool operator!=(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T0, T1, T2, T3, T4> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
__host__ __device__
bool operator==(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5> &y){
  return (
thrust::get<0>(x)
 == 
thrust::get<0>(y)
) && (
thrust::get<1>(x)
 == 
thrust::get<1>(y)
) && (
thrust::get<2>(x)
 == 
thrust::get<2>(y)
) && (
thrust::get<3>(x)
 == 
thrust::get<3>(y)
) && (
thrust::get<4>(x)
 == 
thrust::get<4>(y)
) && (
thrust::get<5>(x)
 == 
thrust::get<5>(y)
);
}
template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
__host__ __device__
bool operator!=(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
__host__ __device__
bool operator==(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &y){
  return (
thrust::get<0>(x)
 == 
thrust::get<0>(y)
) && (
thrust::get<1>(x)
 == 
thrust::get<1>(y)
) && (
thrust::get<2>(x)
 == 
thrust::get<2>(y)
) && (
thrust::get<3>(x)
 == 
thrust::get<3>(y)
) && (
thrust::get<4>(x)
 == 
thrust::get<4>(y)
) && (
thrust::get<5>(x)
 == 
thrust::get<5>(y)
) && (
thrust::get<6>(x)
 == 
thrust::get<6>(y)
);
}
template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
__host__ __device__
bool operator!=(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
__host__ __device__
bool operator==(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &y){
  return (
thrust::get<0>(x)
 == 
thrust::get<0>(y)
) && (
thrust::get<1>(x)
 == 
thrust::get<1>(y)
) && (
thrust::get<2>(x)
 == 
thrust::get<2>(y)
) && (
thrust::get<3>(x)
 == 
thrust::get<3>(y)
) && (
thrust::get<4>(x)
 == 
thrust::get<4>(y)
) && (
thrust::get<5>(x)
 == 
thrust::get<5>(y)
) && (
thrust::get<6>(x)
 == 
thrust::get<6>(y)
) && (
thrust::get<7>(x)
 == 
thrust::get<7>(y)
);
}
template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
__host__ __device__
bool operator!=(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
__host__ __device__
bool operator==(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &y){
  return (
thrust::get<0>(x)
 == 
thrust::get<0>(y)
) && (
thrust::get<1>(x)
 == 
thrust::get<1>(y)
) && (
thrust::get<2>(x)
 == 
thrust::get<2>(y)
) && (
thrust::get<3>(x)
 == 
thrust::get<3>(y)
) && (
thrust::get<4>(x)
 == 
thrust::get<4>(y)
) && (
thrust::get<5>(x)
 == 
thrust::get<5>(y)
) && (
thrust::get<6>(x)
 == 
thrust::get<6>(y)
) && (
thrust::get<7>(x)
 == 
thrust::get<7>(y)
) && (
thrust::get<8>(x)
 == 
thrust::get<8>(y)
);
}
template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
__host__ __device__
bool operator!=(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &y){
  return ! (x==y);
}

}
