#pragma once

#include <thrusting/list.h>
#include <thrusting/detail/iterator.h>

#include <sstream>
#include <iostream>

namespace thrusting {

// make string format of list -> [a, b, c]
template<typename Iterator>
std::string make_string(const detail::list<Iterator> &xs){
  std::stringstream ss;
  ss << "[";
  Iterator end = xs.end(); thrust::advance(end, -1);
  for(Iterator it = xs.begin(); it != end; thrust::advance(it, 1)){
    ss << thrusting::iterator_value_of(it);
    ss << ", ";
  }
  ss << thrusting::iterator_value_of(end);
  ss << "]";
  return ss.str();
}
  
}
