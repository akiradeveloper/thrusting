#include <thrust/iterator/transform_iterator.h>

#include <thrusting/functional.h>

namespace thrusting {

namespace detail {

template<typename UnaryFunction, typename Input>
struct gather_iterator {
  typedef typename transform_iterator<UnaryFunction, Input> type;
};  

} // END detail

/*
  impl but not tested
*/
template<typename Input, typename Map>
detail::gather_iterator<detail::_for_map<Map>, Input>::type make_gather_iterator(
  Input input,
  Map map
){
  return thrust::make_transform_iterator(
    input,
    for_map(map));
}

} // END thrusting
