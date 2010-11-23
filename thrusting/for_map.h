#include <thrust/iterator/iterator_traits.h>

#include <thrusting/iterator.h>

namespace thrusting {
namespace detail {

template<typename Map>
struct device_for_map :public thrust::unary_function<
  typename thrust::iterator_difference<Map>::type,
  typename thrust::iterator_value<Map>::type> {
  Map _it;
  typedef typename thrust::iterator_value<Map>::type T;
  typedef typename thrust::iterator_difference<Map>::type Index;
  device_for_map(Map it)
  :_it(it){}
  __host__ __device__
  T operator()(Index idx){
    return iterator_value_at(idx, _it, thrust::device_space_tag());
  }
};

template<typename Map>
struct host_for_map :public thrust::unary_function<
  typename thrust::iterator_difference<Map>::type,
  typename thrust::iterator_value<Map>::type> {
  Map _it;
  typedef typename thrust::iterator_value<Map>::type T;
  typedef typename thrust::iterator_difference<Map>::type Index;
  host_for_map(Map it)
  :_it(it){}
  __host__ __device__
  T operator()(Index idx){
    return iterator_value_at(idx, _it, thrust::host_space_tag());
  }
};

template<typename Map>
struct any_for_map :public thrust::unary_function<
  typename thrust::iterator_difference<Map>::type,
  typename thrust::iterator_value<Map>::type> {
  Map _it;
  typedef typename thrust::iterator_value<Map>::type T;
  typedef typename thrust::iterator_difference<Map>::type Index;
  any_for_map(Map it)
  :_it(it){}
  T operator()(Index idx){
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

template<thrust::host_space_tag, typename Map>
struct _for_map {
  typedef typename host_for_map<Map> type;
};

template<thrust::device_space_tag, typename Map>
struct _for_map {
  typedef typename device_for_map<Map> type;
};

template<thrust::any_space_tag, typename Map>
struct _for_map {
  typedef typename any_for_map<Map> type;
};

} // END detail

/*
  [a] :: of some space -> Int -> a
  (!!) in Haskell
*/
template<typename Space, typename Iterator>
typename detail::_for_map<Space, Iterator>::type for_map(Iterator it){
  typedef typename thrust::iterator_space<Iterator>::type Space;
  return detail::_for_map<Space, Iterator>::type(it);
}

} // END thrusting
