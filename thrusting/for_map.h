#pragma once

#include <thrust/iterator/iterator_traits.h>

#include <thrusting/iterator.h>
#include <thrusting/functional.h>

namespace thrusting {
namespace detail {

template<typename Map>
struct device_for_map :public thrust::unary_function<
  typename thrust::iterator_difference<Map>::type,
  typename thrust::iterator_value<Map>::type> {
  typedef typename thrust::iterator_value<Map>::type T;
  typedef typename thrust::iterator_difference<Map>::type Index;
  Map _it;
  device_for_map(Map it)
  :_it(it){}
  __host__ __device__
  T operator()(Index idx) const {
    return iterator_value_at(idx, _it, thrust::device_space_tag());
  }
};

template<typename Map>
struct host_for_map :public thrust::unary_function<
  typename thrust::iterator_difference<Map>::type,
  typename thrust::iterator_value<Map>::type> {
  typedef typename thrust::iterator_value<Map>::type T;
  typedef typename thrust::iterator_difference<Map>::type Index;
  Map _it;
  host_for_map(Map it)
  :_it(it){}
  T operator()(Index idx) const {
    return iterator_value_at(idx, _it, thrust::host_space_tag());
  }
};

template<typename Map>
struct any_for_map :public thrust::unary_function<
  typename thrust::iterator_difference<Map>::type,
  typename thrust::iterator_value<Map>::type> {
  typedef typename thrust::iterator_value<Map>::type T;
  typedef typename thrust::iterator_difference<Map>::type Index;
  Map _it;
  any_for_map(Map it)
  :_it(it){}
  T operator()(Index idx) const {
    return iterator_value_at(idx, _it, thrust::any_space_tag());
  }
};

/*
  dispatches space tag to template type
*/
/*
  use if TMP.
*/
template<typename Space, typename Map>
struct _for_map {};

template<typename Map>
struct _for_map<thrust::device_space_tag, Map> {
  typedef device_for_map<Map> type;
};

template<typename Map>
struct _for_map<thrust::host_space_tag, Map> {
  typedef host_for_map<Map> type;
};

template<typename Map>
struct _for_map<thrust::any_space_tag, Map> {
  typedef any_for_map<Map> type;
};

} // END detail

template<typename Map>
detail::device_for_map<Map> for_map(Map it){
  return detail::device_for_map<Map>(it);
}

/*
  [a] :: of some space -> Int -> a
  (!!) in Haskell
*/
//template<typename Map>
//typename detail::_for_map<typename thrust::iterator_space<Map>::type, Map>::type for_map(Map it){
//  typedef typename thrust::iterator_space<Map>::type Space;
//  return detail::_for_map<Space, Map>::type(it);
//}

} // END thrusting
