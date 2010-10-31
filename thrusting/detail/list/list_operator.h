#pragma once

#include <thrusting/list.h>

#include <thrust/equal.h>
#include <sstream>
#include <iostream>

namespace thrusting {
namespace op {
namespace list {

template<typename A>
std::ostream &operator<<(std::ostream &os, const detail::list<A> &a){
  std::stringstream ss;
  ss << "[";
  for(size_t i=0; i<a.length()-1; i++){
    ss << *(a.head()+i);
    ss << ", ";
  }
  ss << *(a.head()+a.length()-1);
  ss << "]";
  os << ss.str();
  return os;
}

template<typename A>
bool operator==(const detail::list<A> &xs, const detail::list<A> &ys){
  if(xs.length() != ys.length()){ return false; }
  return thrust::equal(xs.head(), xs.head()+xs.length(), ys.head());
}

template<typename A>
bool operator!=(const detail::list<A> &xs, const detail::list<A> &ys){
  return !( xs == ys );
}

}
}
}

