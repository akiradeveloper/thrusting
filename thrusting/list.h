#pragma once

using namespace thrusting::op::list;

#include "list/list.h"

#include <thrust/equal.h>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

#include <iostream>
#include <sstream>

namespace thrusting {

template<typename A>
list<A> make_list(size_t n, A head) {
  return list<A>(n, head);
}

template<typename T>
list<A> make_list(thrust::device_vector<T> xs){
  return make_list(xs.size(), xs.begin());
}

template<typename T>
list<A> make_list(thrust::host_vector<T> xs){
  return make_list(xs.size(), xs.begin());
}

} // end thrusting

#include "list/list_operator.h"
//#include "list/list_operator_a_a_a.h"
//#include "list/list_operator_a_b_a.h"
//#include "list/list_operator_a_a.h"
