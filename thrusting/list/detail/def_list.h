#pragma once

#include <iostream>

#include <thrust/equal.h>
#include <thrust/advance.h>

namespace thrusting {
namespace detail {

template<typename Iterator>
class list {
  size_t _n;
  Iterator _head;
public:
  list(size_t n, Iterator head)
  :_n(n), _head(head){}

  size_t length() const {
    return _n;
  }
  // should be removed?
  Iterator head() const {
    return _head;
  }

  Iterator begin() const {
    return head();
  }

  Iterator end() const {
    Iterator it = begin();
    thrust::advance(it, length());
    return it;
  } 

  template<typename Iterator2>
  bool operator==(const list<Iterator2> &ys) const {
    if(length() != ys.length()){ return false; }
    return thrust::equal(head(), end(), ys.head());
  }

  template<typename Iterator2>
  bool operator!=(const list<Iterator2> &ys) const {
    return !( *(this) == ys );
  }
};

} // END detail
} // END thrusting
