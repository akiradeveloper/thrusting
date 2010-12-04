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

template<typename F>
class flipper :public thrust::binary_function<
typename F::second_argument_type,
typename F::first_argument_type,
typename F::result_type> {
  F _f;
public:
  flipper(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  const typename F::second_argument_type &b, const typename F::first_argument_type &a) const {
    return _f(a, b);
  }
};

/*
  flip the arguments of given binary function
  a->b->c -> b->a->c
*/
template<typename F>
flipper<F> flip(F f){
  return flipper<F>(f);
}

template<typename F>
class binder1st :public thrust::unary_function<
  typename F::second_argument_type,
  typename F::result_type> {
  F _f;
  typename F::first_argument_type _a;
public:
  binder1st(F f, const typename F::first_argument_type &a)
  :_f(f), _a(a){}
  __host__ __device__
  typename F::result_type operator()(const typename F::second_argument_type &b) const {
    return _f(_a, b);
  }
};

/*
  bind1st
  a->b->c -> a -> b->c
*/
template<typename F>
binder1st<F> bind1st(F f, const typename F::first_argument_type &a) {
  return binder1st<F>(f, a);
}

/*
  bind2nd
  a->b->c -> b -> a->c
*/
template<typename F>
binder1st<flipper<F> > bind2nd(F f, const typename F::second_argument_type &b) {
  return thrusting::bind1st(flip(f), b);
}

template<typename F>
class currier :public thrust::binary_function<
typename thrust::tuple_element<0, typename F::argument_type>::type, 
typename thrust::tuple_element<1, typename F::argument_type>::type, 
typename F::result_type> {
  F _f;
public:
  currier(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  const typename thrust::tuple_element<0, typename F::argument_type>::type &a, 
  const typename thrust::tuple_element<1, typename F::argument_type>::type &b) const {
    /*
      should be once store the tuple because it has not reference
    */
    return _f(thrust::make_tuple(a, b));
  }
};

/*
  (a,b)->c -> a->b->c
*/
template<typename F>
currier<F> curry(F f){
  return currier<F>(f);
}

template<typename F>
class uncurrier :public thrust::unary_function<
thrust::tuple<typename F::first_argument_type, typename F::second_argument_type>, 
typename F::result_type> {
  F _f;
public:
  uncurrier(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  const thrust::tuple<typename F::first_argument_type, typename F::second_argument_type> &t) const {
    return _f(thrust::get<0>(t), thrust::get<1>(t));
  }
};  

/*
  a->b->c -> (a,b)->c
*/
template<typename F>
uncurrier<F> uncurry(F f){
  return uncurrier<F>(f);
}

template<typename F, typename G>
class composer :public thrust::unary_function<typename F::argument_type, typename G::result_type> {
  F _f;
  G _g;
public:
  composer(F f, G g)
  :_f(f), _g(g){}
  __host__ __device__
  typename F::result_type operator()(const typename G::argument_type &x) const {
    typename G::result_type y = _g(x);
    return _f(y);
  }
};

/*
  f * g
  b->c -> a->b -> a->c
*/
template<typename F, typename G>
composer<F, G> compose(F f, G g){
  return composer<F, G>(f, g);
}

template<typename In, typename Out>
class constant_functor {
  Out _value;
public:
  constant_functor(Out value)
  :_value(value){} 
  __host__ __device__
  Out operator()(const In &in) const {
    return _value;
  }
};

template<typename In, typename Out>
constant_functor<In, Out> make_constant_functor(Out value){
  return constant_functor<In, Out>(value);
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

template<typename A, typename B>
multiplies<A, B> make_multiply_functor(){
  return multiplies<A, B>();
}

/*
  a -> b -> (a/b)::a
*/
template<typename A, typename B>
struct divides :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x / y;
  }
};

template<typename A, typename B>
divides<A, B> make_divide_functor(){
  return divides<A, B>();
}

/*
  a -> b -> (a<<b)::a
*/
template<typename A, typename B>
struct left_shift :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x << y;
  }
};

template<typename A, typename B>
left_shift<A, B> make_left_shift_functor(){
  return left_shift<A, B>();
}

/*
  a -> b -> (a>>b)::a
*/
template<typename A, typename B>
struct right_shift :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x >> y;
  }
};

template<typename A, typename B>
right_shift<A, B> make_right_shift_functor(){
  return right_shift<A, B>();
}

} // END thrusting
