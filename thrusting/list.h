#pragma once

#include <thrust/equal.h>

#include <iostream>
#include <sstream>

using namespace thrusting::op::list;

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

template<typename A>
list<A> make_list(size_t n, A head) {
  return list<A>(n, head);
}

} // end thrusting

#include "list/list_operator.h"
#include "list/list_operator_a_a_a.h"
#include "list/list_operator_a_b_a.h"
#include "list/list_operator_a_a.h"
