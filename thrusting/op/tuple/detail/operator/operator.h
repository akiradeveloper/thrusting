
#pragma once
#include <thrusting/tuple.h>

  namespace thrusting {
  
template<typename X0, typename X1>
__host__ __device__
thrust::tuple<X0, X1> operator+(
const thrust::tuple<X0, X1> &x, const thrust::tuple<X0, X1> &y){
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

template<typename X0, typename X1>
__host__ __device__
thrust::tuple<X0, X1> operator-(
const thrust::tuple<X0, X1> &x, const thrust::tuple<X0, X1> &y){
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

template<typename X0, typename X1, typename X2>
__host__ __device__
thrust::tuple<X0, X1, X2> operator+(
const thrust::tuple<X0, X1, X2> &x, const thrust::tuple<X0, X1, X2> &y){
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

template<typename X0, typename X1, typename X2>
__host__ __device__
thrust::tuple<X0, X1, X2> operator-(
const thrust::tuple<X0, X1, X2> &x, const thrust::tuple<X0, X1, X2> &y){
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

template<typename X0, typename X1, typename X2, typename X3>
__host__ __device__
thrust::tuple<X0, X1, X2, X3> operator+(
const thrust::tuple<X0, X1, X2, X3> &x, const thrust::tuple<X0, X1, X2, X3> &y){
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

template<typename X0, typename X1, typename X2, typename X3>
__host__ __device__
thrust::tuple<X0, X1, X2, X3> operator-(
const thrust::tuple<X0, X1, X2, X3> &x, const thrust::tuple<X0, X1, X2, X3> &y){
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

template<typename X0, typename X1, typename X2, typename X3, typename X4>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4> operator+(
const thrust::tuple<X0, X1, X2, X3, X4> &x, const thrust::tuple<X0, X1, X2, X3, X4> &y){
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

template<typename X0, typename X1, typename X2, typename X3, typename X4>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4> operator-(
const thrust::tuple<X0, X1, X2, X3, X4> &x, const thrust::tuple<X0, X1, X2, X3, X4> &y){
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

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5> operator+(
const thrust::tuple<X0, X1, X2, X3, X4, X5> &x, const thrust::tuple<X0, X1, X2, X3, X4, X5> &y){
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

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5> operator-(
const thrust::tuple<X0, X1, X2, X3, X4, X5> &x, const thrust::tuple<X0, X1, X2, X3, X4, X5> &y){
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

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5, X6> operator+(
const thrust::tuple<X0, X1, X2, X3, X4, X5, X6> &x, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6> &y){
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

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5, X6> operator-(
const thrust::tuple<X0, X1, X2, X3, X4, X5, X6> &x, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6> &y){
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

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> operator+(
const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> &x, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> &y){
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

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> operator-(
const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> &x, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> &y){
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

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7, typename X8>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> operator+(
const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> &x, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> &y){
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

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7, typename X8>
__host__ __device__
thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> operator-(
const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> &x, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> &y){
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

  }
  
