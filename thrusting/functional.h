#pragma once

/*
  functional.h in Thrusting library supports
  several useful functions such as 
  
  bind1st
  bind2nd
  curry, uncurry
  compose

  Enjoy Functional Programming!
*/

#include <thrust/functional.h>
#include <thrust/tuple.h>
#include <thrust/iterator/iterator_traits.h>

#include <thrusting/iterator.h>

namespace thrusting {

namespace detail {

template<typename F>
struct _flip :public thrust::binary_function<
typename F::second_argument_type,
typename F::first_argument_type,
typename F::result_type> {
  F _f;
  _flip(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  const typename F::second_argument_type &b, const typename F::first_argument_type &a) const {
    return _f(a, b);
  }
};

template<typename F>
struct _curry :public thrust::binary_function<
typename thrust::tuple_element<0, typename F::argument_type>::type, 
typename thrust::tuple_element<1, typename F::argument_type>::type, 
typename F::result_type> {
  F _f;
  _curry(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  const typename thrust::tuple_element<0, typename F::argument_type>::type &a, 
  const typename thrust::tuple_element<1, typename F::argument_type>::type &b) const {
    return _f(thrust::make_tuple(a, b));
  }
};

template<typename F>
struct _uncurry :public thrust::unary_function<
thrust::tuple<typename F::first_argument_type, typename F::second_argument_type>, 
typename F::result_type> {
  F _f;
  _uncurry(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  thrust::tuple<typename F::first_argument_type, typename F::second_argument_type> t) const {
    return _f(thrust::get<0>(t), thrust::get<1>(t));
  }
};  

template<typename F, typename G>
struct _compose :public thrust::unary_function<typename F::argument_type, typename G::result_type> {
  F _f;
  G _g;
  _compose(F f, G g)
  :_f(f), _g(g){}
  __host__ __device__
  typename F::result_type operator()(const typename G::argument_type &x) const {
    return _f(_g(x));
  }
};

template<typename F>
struct _bind1st :public thrust::unary_function<
  typename F::second_argument_type,
  typename F::result_type> {
  F _f;
  typename F::first_argument_type _a;
  _bind1st(F f, const typename F::first_argument_type &a)
  :_f(f), _a(a){}
  __host__ __device__
  typename F::result_type operator()(const typename F::second_argument_type &b) const {
    return _f(_a, b);
  }
};

} // END detail

/*
  flip the arguments of given binary function
  a->b->c -> b->a->c
*/
template<typename F>
detail::_flip<F> flip(F f){
  return detail::_flip<F>(f);
}

/*
  bind1st
  a->b->c -> a -> b->c
*/
template<typename F>
detail::_bind1st<F> bind1st(F f, const typename F::first_argument_type a) {
  return detail::_bind1st<F>(f, a);
}

/*
  bind2nd
  a->b->c -> b -> a->c
*/
template<typename F>
detail::_bind1st< detail::_flip<F> > bind2nd(F f, const typename F::second_argument_type &b) {
  return thrusting::bind1st(flip(f), b);
}

/*
  (a,b)->c -> a->b->c
*/
template<typename F>
detail::_curry<F> curry(F f){
  return detail::_curry<F>(f);
}

/*
  a->b->c -> (a,b)->c
*/
template<typename F>
detail::_uncurry<F> uncurry(F f){
  return detail::_uncurry<F>(f);
}

/*
  f * g
  b->c -> a->b -> a->c
*/
template<typename F, typename G>
detail::_compose<F, G> compose(F f, G g){
  return detail::_compose<F, G>(f, g);
}

/*
  a -> b -> (a*b)::b
*/
template<typename A, typename B>
struct multiplies :public thrust::binary_function<A, B, B> {
  __host__ __device__
  B operator()(const A &x, const B &y) const {
    return x * y;
  }
};

/*
  a -> b -> (a/b)
*/
template<typename A, typename B>
struct divides :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x / y;
  }
};

/*
  a -> b -> (a<<b)
*/
template<typename A, typename B>
struct left_shift :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x << y;
  }
};

/*
  a -> b -> (a>>b)
*/
template<typename A, typename B>
struct right_shift :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x >> y;
  }
};

} // end thrusting
