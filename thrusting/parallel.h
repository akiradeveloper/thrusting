#pragma once

#include "functional.h"
#include "parallel_operator_a_a_a.h"
#include "parallel_operator_a_b_a.h"
#include "parallel_operator_a_a.h"

#include <thrust/transform.h>
#include <thrust/functional.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/copy.h>

#include <string>

namespace thrusting {

template<typename A>
struct parallel {
  size_t n;
  A head;
  parallel(size_t n_, A &head_)
  :n(n_), head(head_){}
  size_t size(){
    return n;
  }
  const A &head(){
    return head;
  }
  void operator<<(A from){
    thrust::copy(from, from+size(), head);
  }
  bool operator==(A with){
    return thrust::equal(head(), head()+size(), with);
  }
  bool operator==(const parallel<A> &with){
    return (*this)==with.head();
  }
};

template<typename A>
std::ostream &operator<<(std::ostream &os, const parallel<A> &a){
  std::string s;
  s += "[";
  for(size_t i=0; i<a.size()-1; i++){
    s += *(a.head()+i);
    s += ", ";
  }
  s += *(a.head()+a.size()-1);
  s += "]";
  os << s;
  return os;
}

template<typename A>
parallel<A> make_parallel(size_t n, A head){
  return parallel<A>(n, head);
}

} // end thrusting

