#pragma once

#include <thrust/equal.h>

namespace thrusting {
namespace detail {

template<typename A>
struct list {
  size_t _n;
  A _head;
  list(size_t n_, A head_)
  :_n(n_), _head(head_){}
  A head() const {
    return _head;
  }
  size_t length() const {
    return _n;
  }
  bool operator==(const list<A> &ys) const {
    if(length() != ys.length()){ return false; }
    return thrust::equal(head(), head()+length(), ys.head());
  }
  bool operator!=(const list<A> &ys) const {
    return !( *(this) == ys );
  }
};

} // end detail
} // end thrusting
