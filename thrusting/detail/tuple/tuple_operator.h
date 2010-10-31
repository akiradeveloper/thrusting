
#pragma once
#include <thrusting/tuple.h>
#include <iostream>
#include <sstream>

namespace thrusting {
namespace op {
namespace tuple {


template<typename T0, typename T1>
__host__ __device__
thrust::tuple<T0, T1> operator+(const thrust::tuple<T0, T1> &x, const thrust::tuple<T0, T1> &y){
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

template<typename T0, typename T1>
__host__ __device__
thrust::tuple<T0, T1> operator-(const thrust::tuple<T0, T1> &x, const thrust::tuple<T0, T1> &y){
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

template<typename T0, typename T1>
__host__ __device__
thrust::tuple<T0, T1> operator*(const thrust::tuple<T0, T1> &x, const thrust::tuple<T0, T1> &y){
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

template<typename T0, typename T1>
__host__ __device__
thrust::tuple<T0, T1> operator/(const thrust::tuple<T0, T1> &x, const thrust::tuple<T0, T1> &y){
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

template<typename T0, typename T1, typename T2>
__host__ __device__
thrust::tuple<T0, T1, T2> operator+(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T0, T1, T2> &y){
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

template<typename T0, typename T1, typename T2>
__host__ __device__
thrust::tuple<T0, T1, T2> operator-(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T0, T1, T2> &y){
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

template<typename T0, typename T1, typename T2>
__host__ __device__
thrust::tuple<T0, T1, T2> operator*(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T0, T1, T2> &y){
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

template<typename T0, typename T1, typename T2>
__host__ __device__
thrust::tuple<T0, T1, T2> operator/(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T0, T1, T2> &y){
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

template<typename T0, typename T1, typename T2, typename T3>
__host__ __device__
thrust::tuple<T0, T1, T2, T3> operator+(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T0, T1, T2, T3> &y){
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

template<typename T0, typename T1, typename T2, typename T3>
__host__ __device__
thrust::tuple<T0, T1, T2, T3> operator-(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T0, T1, T2, T3> &y){
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

template<typename T0, typename T1, typename T2, typename T3>
__host__ __device__
thrust::tuple<T0, T1, T2, T3> operator*(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T0, T1, T2, T3> &y){
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

template<typename T0, typename T1, typename T2, typename T3>
__host__ __device__
thrust::tuple<T0, T1, T2, T3> operator/(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T0, T1, T2, T3> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4> operator+(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T0, T1, T2, T3, T4> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4> operator-(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T0, T1, T2, T3, T4> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4> operator*(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T0, T1, T2, T3, T4> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4> operator/(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T0, T1, T2, T3, T4> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &y){
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

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
__host__ __device__
thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &y){
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
}
}

