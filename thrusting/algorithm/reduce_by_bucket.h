#include <thrust/reduce.h>
#include <thrust/fill.h>
#include <thrust/find.h>
#include <thrust/transform.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/scatter.h>
#include <thrust/iterator/constant_iterator.h>

#include <thrusting/iterator.h>
#include <thrusting/functional.h>

// for debug
#include <thrusting/list.h>

namespace thrusting {
  

template<
typename Size1,
typename Size2,
typename InputIterator1,
typename InputIterator2,
typename OutputIterator1,
typename OutputIterator2,
typename TmpIterator1,
typename TmpIterator2,
typename T>
void reduce_by_bucket(
  Size1 n_value,
  InputIterator1 idx,
  InputIterator2 value,
  Size2 n_bucket,
  OutputIterator1 cnt_output,
  OutputIterator2 value_output,	
  TmpIterator1 cnt_output_tmp1,
  TmpIterator2 cnt_output_tmp2,
  const T &null_value
){
  typedef typename thrust::iterator_value<OutputIterator1>::type Count;
  typedef typename thrust::iterator_value<TmpIterator1>::type Count1;
  typedef typename thrust::iterator_value<TmpIterator2>::type Count2;

  thrust::pair<TmpIterator2, TmpIterator1> end;
  end = thrust::reduce_by_key(
    idx,
    thrusting::advance(n_value, idx),
    thrust::make_constant_iterator(1),
    cnt_output_tmp2, // [idx_a,idx_b,...,*,*,...], where to jump
    cnt_output_tmp1); // [a,b,...,*,*,...]

  Size2 n_non_empty = end.first - cnt_output_tmp2;
  
  Count null_cnt(0);
  thrust::fill(
    cnt_output,
    thrusting::advance(n_bucket, cnt_output),
    null_cnt);   

  thrust::scatter(
    cnt_output_tmp1,
    thrusting::advance(n_non_empty, cnt_output_tmp1),
    cnt_output_tmp2,
    cnt_output);
  
  thrust::reduce_by_key(
    idx,
    thrusting::advance(n_value, idx),
    value,
    cnt_output_tmp2, 
    value_output);   

  thrust::scatter(
    value_output,
    thrusting::advance(n_non_empty, value_output),
    cnt_output_tmp2,
    value_output);

  /*
    cnt_output_tmp1 will be used as stencil in replace_if
    initialize all bit off 
  */
  thrust::fill(
    cnt_output_tmp1,
    thrusting::advance(n_bucket, cnt_output_tmp1),
    Count1(0));

  /*
    on bit  
  */
  thrust::transform_if(
    cnt_output, // means nothing 
    thrusting::advance(n_bucket, cnt_output),
    cnt_output, // stencil
    cnt_output_tmp1, // result
    thrusting::constant<Count1>(1), // op return 1 if stencil elem is 0
    thrusting::bind2nd(thrust::equal_to<Count>(), Count(0))); // pred receiving stencil
  
  /*
    replace by null_value if the stencil is on
  */
  thrust::replace_if(
    value_output,
    thrusting::advance(n_bucket, value_output),
    cnt_output_tmp1, // stencil
    thrust::identity<Count1>(),
    null_value); // new value
}

} // END thrusting
