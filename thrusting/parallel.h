#pragma once

#include <thrust/transform.h>
#include <thrust/functional.h>
#include <thrust/equal.h>
#include <thrust/iterator/iterator_traits.h>

#include <iostream>
#include <sstream>

namespace thrust {

template<typename A>
struct parallel {
  size_t _n;
  A _head;
  parallel(size_t n_, A head_)
  :_n(n_), _head(head_){}
  size_t length() const {
    return _n;
  }
  A head() const {
    return _head;
  }
  bool operator==(A with) const {
    return thrust::equal(head(), head()+length(), with);
  }
  bool operator==(const parallel<A> &with) const {
    if(length() != with.length()){ return false; }
    return (*this)==with.head();
  }
};

template<typename A>
std::ostream &operator<<(std::ostream &os, const parallel<A> &a){
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

// Akira Hayakawa Notes, 2010 10/26 22:09
// iterator should be copied
template<typename A>
parallel<A> make_parallel(size_t n, A head) {
  return parallel<A>(n, head);
}

} // end thrust

#include "parallel/parallel_operator_a_a_a.h"
#include "parallel/parallel_operator_a_b_a.h"
#include "parallel/parallel_operator_a_a.h"
