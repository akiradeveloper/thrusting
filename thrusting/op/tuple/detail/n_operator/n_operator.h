
#pragma once
#include <thrust/tuple.h>

namespace thrusting {
namespace op {

template<typename X0, typename X1, typename X2>
__host__ __device__
thrust::tuple<X0, X1> operator/(const thrust::tuple<X0, X1> &t, const X2 &x){
  return thrust::make_tuple(
thrust::get<0>(t)
 / x, 
thrust::get<1>(t)
 / x);
}

template<typename X0, typename X1, typename X2, typename X3>
__host__ __device__
thrust::tuple<X0, X1, X2> operator/(const thrust::tuple<X0, X1, X2> &t, const X3 &x){
  return thrust::make_tuple(
thrust::get<0>(t)
 / x, 
thrust::get<1>(t)
 / x, 
thrust::get<2>(t)
 / x);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4>
__host__ __device__
thrust::tuple<X0, X1, X2, X3> operator/(const thrust::tuple<X0, X1, X2, X3> &t, const X4 &x){
  return thrust::make_tuple(
thrust::get<0>(t)
 / x, 
thrust::get<1>(t)
 / x, 
thrust::get<2>(t)
 / x, 
thrust::get<3>(t)
 / x);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4> operator/(const thrust::tuple<X0, X1, X2, X3, X4> &t, const X5 &x){
  return thrust::make_tuple(
thrust::get<0>(t)
 / x, 
thrust::get<1>(t)
 / x, 
thrust::get<2>(t)
 / x, 
thrust::get<3>(t)
 / x, 
thrust::get<4>(t)
 / x);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5> operator/(const thrust::tuple<X0, X1, X2, X3, X4, X5> &t, const X6 &x){
  return thrust::make_tuple(
thrust::get<0>(t)
 / x, 
thrust::get<1>(t)
 / x, 
thrust::get<2>(t)
 / x, 
thrust::get<3>(t)
 / x, 
thrust::get<4>(t)
 / x, 
thrust::get<5>(t)
 / x);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5, X6> operator/(const thrust::tuple<X0, X1, X2, X3, X4, X5, X6> &t, const X7 &x){
  return thrust::make_tuple(
thrust::get<0>(t)
 / x, 
thrust::get<1>(t)
 / x, 
thrust::get<2>(t)
 / x, 
thrust::get<3>(t)
 / x, 
thrust::get<4>(t)
 / x, 
thrust::get<5>(t)
 / x, 
thrust::get<6>(t)
 / x);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7, typename X8>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> operator/(const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> &t, const X8 &x){
  return thrust::make_tuple(
thrust::get<0>(t)
 / x, 
thrust::get<1>(t)
 / x, 
thrust::get<2>(t)
 / x, 
thrust::get<3>(t)
 / x, 
thrust::get<4>(t)
 / x, 
thrust::get<5>(t)
 / x, 
thrust::get<6>(t)
 / x, 
thrust::get<7>(t)
 / x);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7, typename X8, typename X9>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> operator/(const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> &t, const X9 &x){
  return thrust::make_tuple(
thrust::get<0>(t)
 / x, 
thrust::get<1>(t)
 / x, 
thrust::get<2>(t)
 / x, 
thrust::get<3>(t)
 / x, 
thrust::get<4>(t)
 / x, 
thrust::get<5>(t)
 / x, 
thrust::get<6>(t)
 / x, 
thrust::get<7>(t)
 / x, 
thrust::get<8>(t)
 / x);
}

}
}
 

namespace thrusting {
namespace op {

template<typename X0, typename X1, typename X2>
thrust::tuple<X0, X1> operator*(const X2 &x, const thrust::tuple<X0, X1> &t){
  return thrust::make_tuple(x * 
thrust::get<0>(t)
, x * 
thrust::get<1>(t)
);
}

template<typename X0, typename X1, typename X2, typename X3>
thrust::tuple<X0, X1, X2> operator*(const X3 &x, const thrust::tuple<X0, X1, X2> &t){
  return thrust::make_tuple(x * 
thrust::get<0>(t)
, x * 
thrust::get<1>(t)
, x * 
thrust::get<2>(t)
);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4>
thrust::tuple<X0, X1, X2, X3> operator*(const X4 &x, const thrust::tuple<X0, X1, X2, X3> &t){
  return thrust::make_tuple(x * 
thrust::get<0>(t)
, x * 
thrust::get<1>(t)
, x * 
thrust::get<2>(t)
, x * 
thrust::get<3>(t)
);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5>
thrust::tuple<X0, X1, X2, X3, X4> operator*(const X5 &x, const thrust::tuple<X0, X1, X2, X3, X4> &t){
  return thrust::make_tuple(x * 
thrust::get<0>(t)
, x * 
thrust::get<1>(t)
, x * 
thrust::get<2>(t)
, x * 
thrust::get<3>(t)
, x * 
thrust::get<4>(t)
);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6>
thrust::tuple<X0, X1, X2, X3, X4, X5> operator*(const X6 &x, const thrust::tuple<X0, X1, X2, X3, X4, X5> &t){
  return thrust::make_tuple(x * 
thrust::get<0>(t)
, x * 
thrust::get<1>(t)
, x * 
thrust::get<2>(t)
, x * 
thrust::get<3>(t)
, x * 
thrust::get<4>(t)
, x * 
thrust::get<5>(t)
);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7>
thrust::tuple<X0, X1, X2, X3, X4, X5, X6> operator*(const X7 &x, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6> &t){
  return thrust::make_tuple(x * 
thrust::get<0>(t)
, x * 
thrust::get<1>(t)
, x * 
thrust::get<2>(t)
, x * 
thrust::get<3>(t)
, x * 
thrust::get<4>(t)
, x * 
thrust::get<5>(t)
, x * 
thrust::get<6>(t)
);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7, typename X8>
thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> operator*(const X8 &x, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> &t){
  return thrust::make_tuple(x * 
thrust::get<0>(t)
, x * 
thrust::get<1>(t)
, x * 
thrust::get<2>(t)
, x * 
thrust::get<3>(t)
, x * 
thrust::get<4>(t)
, x * 
thrust::get<5>(t)
, x * 
thrust::get<6>(t)
, x * 
thrust::get<7>(t)
);
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7, typename X8, typename X9>
thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> operator*(const X9 &x, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> &t){
  return thrust::make_tuple(x * 
thrust::get<0>(t)
, x * 
thrust::get<1>(t)
, x * 
thrust::get<2>(t)
, x * 
thrust::get<3>(t)
, x * 
thrust::get<4>(t)
, x * 
thrust::get<5>(t)
, x * 
thrust::get<6>(t)
, x * 
thrust::get<7>(t)
, x * 
thrust::get<8>(t)
);
}

}
}
 
