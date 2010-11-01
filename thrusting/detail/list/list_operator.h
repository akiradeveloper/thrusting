#pragma once

#include <thrusting/list.h>

#include <sstream>
#include <iostream>

namespace thrusting {

template<typename Iterator>
std::string make_string(const detail::list<Iterator> &xs){
  std::stringstream ss;
  ss << "[";
  for(size_t i=0; i<xs.length()-1; i++){
    ss << *(xs.head()+i);
    ss << ", ";
  }
  ss << *(xs.head()+xs.length()-1);
  ss << "]";
  return ss.str();
}
  
namespace op {
namespace list {

template<typename A>
std::ostream &operator<<(std::ostream &os, const detail::list<A> &xs){
  return os << thrusting::make_string(xs);
}

} 
}
}
