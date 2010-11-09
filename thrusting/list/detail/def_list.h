#pragma once

#include <thrust/equal.h>
#include <thrust/advance.h>

namespace thrusting {
namespace detail {

template<typename Iterator>
struct list {
  size_t _n;
  Iterator _head;
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
  bool operator==(const list<Iterator> &ys) const {
    if(length() != ys.length()){ return false; }
    return thrust::equal(head(), head()+length(), ys.head());
  }
  bool operator!=(const list<Iterator> &ys) const {
    return !( *(this) == ys );
  }
};

} // end detail
} // end thrusting
