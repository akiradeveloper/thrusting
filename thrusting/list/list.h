#pragma once

namespace thrusting {

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
};

}
