#pragma once

#include <thrust/functional.h>
#include <thrust/tuple.h>

namespace thrusting {

// a->b->c -> b->a->c
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
_flip<F> flip(F f){
  return _flip<F>(f);
}

// a->b->c -> a -> b->c
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

template<typename F>
_bind1st<F> bind1st(F f, const typename F::first_argument_type a) {
  return _bind1st<F>(f, a);
}

// a->b->c -> b -> a->c
template<typename F>
_bind1st< _flip<F> > bind2nd(F f, const typename F::second_argument_type &b) {
  return thrusting::bind1st(thrusting::flip(f), b);
}

// (a,b)->c -> a->b->c
template<typename F>
struct _uncurry :public thrust::binary_function<
typename thrust::tuple_element<0, typename F::argument_type>::type, 
typename thrust::tuple_element<1, typename F::argument_type>::type, 
typename F::result_type> {
  F _f;
  _uncurry(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  const typename thrust::tuple_element<0, typename F::argument_type>::type &a, 
  const typename thrust::tuple_element<1, typename F::argument_type>::type &b) const {
    return _f(thrust::make_tuple(a, b));
  }
};

template<typename F>
_uncurry<F> uncurry(F f){
  return _uncurry<F>(f);
}

// a->b->c -> (a,b)->c
template<typename F>
struct _curry :public thrust::unary_function<
thrust::tuple<typename F::first_argument_type, typename F::second_argument_type>, 
typename F::result_type> {
  F _f;
  _curry(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  thrust::tuple<typename F::first_argument_type, typename F::second_argument_type> t) const {
    return _f(thrust::get<0>(t), thrust::get<1>(t));
  }
};  

template<typename F>
_curry<F> curry(F f){
  return _curry<F>(f);
}

// a->b -> b->c -> a->c
template<typename F, typename G>
struct _compose :public thrust::unary_function<typename F::argument_type, typename G::result_type> {
  F _f;
  G _g;
  _compose(F f, G g)
  :_f(f), _g(g){}
  __host__ __device__
  typename G::result_type operator()(const typename F::argument_type &x) const {
    return _g(_f(x));
  }
};

template<typename F, typename G>
_compose<F, G> compose(F f, G g){
  return _compose<F, G>(f, g);
}

template<typename A, typename B>
struct multiplies :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x * y;
  }
};

template<typename A, typename B>
struct divides :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x / y;
  }
};

template<typename A, typename B>
struct left_shift :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x << y;
  }
};

template<typename A, typename B>
struct right_shift :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x >> y;
  }
};

} // end thrusting
