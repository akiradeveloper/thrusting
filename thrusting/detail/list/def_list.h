#pragma once

namespace thrusting {
namespace detail {

template<typename A>
struct list {
  size_t _n;
  A _head;
  list(size_t n_, A head_)
  :_n(n_), _head(head_){}
  size_t length() const {
    return _n;
  }
  A head() const {
    return _head;
  }
//  bool operator==(const list<A> &ys) const {
//    return true;
//  }
//  bool operator!=(const list<A> &ys) const {
//    return true;
//  }
};

} // end detail
} // end thrusting
