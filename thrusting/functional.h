#pragma once

#include <thrust/functional.h>
#include <thrust/tuple.h>

namespace thrusting {

// a->b->c -> b->a->c
template<typename F>
struct flip :public thrust::binary_function<
typename F::second_argument_type,
typename F::first_argument_type,
typename F::result_type> {
  F _f;
  flip(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  const typename F::second_argument_type &b, const typename F::first_argument_type &a){
    return _F(a, b);
  }
};

// a->b->c -> a -> b->c
template<typename F>
struct bind1st :public thrust::unary_function<
typename F::second_argument_type,
typename F::result_type> {
  F _f;
  typename F::first_argument _a;
  bind1st(F f, const typename F::first_argument_type &a)
  :_f(f), _a(a){}
  __host__ __device__
  typename F::result_type operator()(const typename F::second_argument_type &b) const {
    return _f(_a, b);
  }
};

// a->b->c -> b -> a->c
template<typename F>
bind1st< flip<F> > bind2nd(F f, typename F::second_argument_type &b){
  return bind1st(b, flip(f));
}

// a->b->c -> b -> a->c
//template<typename F>
//struct bind2st :public thrust::unary_function<
//typename F::first_argument_type,
//typename F::result_type> {
//  F _f;
//  typename F::second_argument _b;
//  bind1st(F f, const typename F::second_argument_type &b)
//  :_f(f), _b(b){}
//  __host__ __device__
//  typename F::result_type operator()(const typename F::first_argument_type &a) const {
//    return _f(a, _b);
//  }
//};

// (a,b)->c -> a->b->c
template<typename F>
struct uncurry :public thrust::binary_function<
typename thrust::tuple_element<0, typename F::argument_type>::type, 
typename thrust::tuple_element<1, typename F::argument_type>::type, 
typename F::result_type> {
  F _f;
  uncurry(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  const typename thrust::tuple_element<0, typename F::argument_type>::type &a, 
  const typename thrust::tuple_element<1, typename F::argument_type>::type &b) const {
    return _f(thrust::make_tuple(a, b));
  }
};

// a->b->c -> (a,b)->c
template<typename F>
struct curry :public thrust::unary_function<
thrust::tuple<typename F::first_argument_type, typename F::second_argument_type>, 
typename F::result_type> {
  F _f;
  curry(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  thrust::tuple<typename F::first_argument_type, typename F::second_argument_type> t) const {
    return _f(thrust::get<0>(t), thrust::get<1>(0));
  }
};  

// a->b -> b->c -> a->c
template<typename F, typename G>
struct compose :public thrust::unary_function<typename F::argument_type, typename G::result_type> {
  F _f;
  G _g;
  compose(F f, G g)
  :_f(f), _g(g){}
  __host__ __device__
  typename G::result_type operator()(const typename F::argument_type &x) const {
    return _g(_f(x));
  }
};

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
