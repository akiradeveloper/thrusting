
#pragma once
#include <thrust/tuple.h>
#include <sstream>
#include <string>
namespace thrusting {

template<typename X0, typename X1>
std::string make_string(const thrust::tuple<X0, X1> &t){
  std::stringstream ss;
  ss << "(" << 
  thrust::get<0>(t)
   << ", " << 
  thrust::get<1>(t)
   << ")";
  return ss.str();
}


template<typename X0, typename X1, typename X2>
std::string make_string(const thrust::tuple<X0, X1, X2> &t){
  std::stringstream ss;
  ss << "(" << 
  thrust::get<0>(t)
   << ", " << 
  thrust::get<1>(t)
   << ", " << 
  thrust::get<2>(t)
   << ")";
  return ss.str();
}


template<typename X0, typename X1, typename X2, typename X3>
std::string make_string(const thrust::tuple<X0, X1, X2, X3> &t){
  std::stringstream ss;
  ss << "(" << 
  thrust::get<0>(t)
   << ", " << 
  thrust::get<1>(t)
   << ", " << 
  thrust::get<2>(t)
   << ", " << 
  thrust::get<3>(t)
   << ")";
  return ss.str();
}


template<typename X0, typename X1, typename X2, typename X3, typename X4>
std::string make_string(const thrust::tuple<X0, X1, X2, X3, X4> &t){
  std::stringstream ss;
  ss << "(" << 
  thrust::get<0>(t)
   << ", " << 
  thrust::get<1>(t)
   << ", " << 
  thrust::get<2>(t)
   << ", " << 
  thrust::get<3>(t)
   << ", " << 
  thrust::get<4>(t)
   << ")";
  return ss.str();
}


template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5>
std::string make_string(const thrust::tuple<X0, X1, X2, X3, X4, X5> &t){
  std::stringstream ss;
  ss << "(" << 
  thrust::get<0>(t)
   << ", " << 
  thrust::get<1>(t)
   << ", " << 
  thrust::get<2>(t)
   << ", " << 
  thrust::get<3>(t)
   << ", " << 
  thrust::get<4>(t)
   << ", " << 
  thrust::get<5>(t)
   << ")";
  return ss.str();
}


template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6>
std::string make_string(const thrust::tuple<X0, X1, X2, X3, X4, X5, X6> &t){
  std::stringstream ss;
  ss << "(" << 
  thrust::get<0>(t)
   << ", " << 
  thrust::get<1>(t)
   << ", " << 
  thrust::get<2>(t)
   << ", " << 
  thrust::get<3>(t)
   << ", " << 
  thrust::get<4>(t)
   << ", " << 
  thrust::get<5>(t)
   << ", " << 
  thrust::get<6>(t)
   << ")";
  return ss.str();
}


template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7>
std::string make_string(const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> &t){
  std::stringstream ss;
  ss << "(" << 
  thrust::get<0>(t)
   << ", " << 
  thrust::get<1>(t)
   << ", " << 
  thrust::get<2>(t)
   << ", " << 
  thrust::get<3>(t)
   << ", " << 
  thrust::get<4>(t)
   << ", " << 
  thrust::get<5>(t)
   << ", " << 
  thrust::get<6>(t)
   << ", " << 
  thrust::get<7>(t)
   << ")";
  return ss.str();
}


template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7, typename X8>
std::string make_string(const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> &t){
  std::stringstream ss;
  ss << "(" << 
  thrust::get<0>(t)
   << ", " << 
  thrust::get<1>(t)
   << ", " << 
  thrust::get<2>(t)
   << ", " << 
  thrust::get<3>(t)
   << ", " << 
  thrust::get<4>(t)
   << ", " << 
  thrust::get<5>(t)
   << ", " << 
  thrust::get<6>(t)
   << ", " << 
  thrust::get<7>(t)
   << ", " << 
  thrust::get<8>(t)
   << ")";
  return ss.str();
}

}
