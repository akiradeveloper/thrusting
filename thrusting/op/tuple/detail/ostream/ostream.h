
#pragma once
#include <thrusting/tuple.h>
#include <iostream>

namespace thrusting {
namespace op {

template<typename X0, typename X1>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<X0, X1> &t){
  os << thrusting::make_string(t);
  return os;
}

template<typename X0, typename X1, typename X2>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<X0, X1, X2> &t){
  os << thrusting::make_string(t);
  return os;
}

template<typename X0, typename X1, typename X2, typename X3>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<X0, X1, X2, X3> &t){
  os << thrusting::make_string(t);
  return os;
}

template<typename X0, typename X1, typename X2, typename X3, typename X4>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<X0, X1, X2, X3, X4> &t){
  os << thrusting::make_string(t);
  return os;
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<X0, X1, X2, X3, X4, X5> &t){
  os << thrusting::make_string(t);
  return os;
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6> &t){
  os << thrusting::make_string(t);
  return os;
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> &t){
  os << thrusting::make_string(t);
  return os;
}

template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7, typename X8>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> &t){
  os << thrusting::make_string(t);
  return os;
}

}
}

