#include <thrusting/algorithm/advance.h>

#include <thrust/distance.h>

/*
  not tested
*/
template<
typename Size,
typename InputIterator
typename Predicate>
Size remove_if(
  Size n,
  InputIterator first,
  Predicate pred
){
  InputIterator tail = remove_if(
    first,
    thrusting::advance(n, input),
    pred);

  return thrusting::distance(input, tail);
}

/*
  not tested
*/
Size sort_out_if(
  Size n,
  InputIterator first,
  OutputIterator trashbox,
  
