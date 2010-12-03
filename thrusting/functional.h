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
struct flip :public thrust::binary_function<
typename F::second_argument_type,
typename F::first_argument_type,
typename F::result_type> {
  F _f;
  flip(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  const typename F::second_argument_type &b, const typename F::first_argument_type &a) const {
    return _f(a, b);
  }
};

} // END detail

/*
  flip the arguments of given binary function
  a->b->c -> b->a->c
*/
template<typename F>
detail::flip<F> flip(F f){
  return detail::flip<F>(f);
}

namespace detail {

template<typename F>
struct bind1st :public thrust::unary_function<
  typename F::second_argument_type,
  typename F::result_type> {
  F _f;
  typename F::first_argument_type _a;
  bind1st(F f, const typename F::first_argument_type &a)
  :_f(f), _a(a){}
  __host__ __device__
  typename F::result_type operator()(const typename F::second_argument_type &b) const {
    return _f(_a, b);
  }
};

} // END detail

/*
  bind1st
  a->b->c -> a -> b->c
*/
template<typename F>
detail::bind1st<F> bind1st(F f, const typename F::first_argument_type &a) {
  return detail::bind1st<F>(f, a);
}

/*
  bind2nd
  a->b->c -> b -> a->c
*/
template<typename F>
detail::bind1st< detail::flip<F> > bind2nd(F f, const typename F::second_argument_type &b) {
  return thrusting::bind1st(flip(f), b);
}

namespace detail {

template<typename F>
struct curry :public thrust::binary_function<
typename thrust::tuple_element<0, typename F::argument_type>::type, 
typename thrust::tuple_element<1, typename F::argument_type>::type, 
typename F::result_type> {
  F _f;
  curry(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  const typename thrust::tuple_element<0, typename F::argument_type>::type &a, 
  const typename thrust::tuple_element<1, typename F::argument_type>::type &b) const {
    return _f(thrust::make_tuple(a, b));
  }
};

} // END detail

/*
  (a,b)->c -> a->b->c
*/
template<typename F>
detail::curry<F> curry(F f){
  return detail::curry<F>(f);
}

namespace detail {

template<typename F>
struct uncurry :public thrust::unary_function<
thrust::tuple<typename F::first_argument_type, typename F::second_argument_type>, 
typename F::result_type> {
  F _f;
  uncurry(F f)
  :_f(f){}
  __host__ __device__
  typename F::result_type operator()(
  thrust::tuple<typename F::first_argument_type, typename F::second_argument_type> t) const {
    return _f(thrust::get<0>(t), thrust::get<1>(t));
  }
};  

} // END detail

/*
  a->b->c -> (a,b)->c
*/
template<typename F>
detail::uncurry<F> uncurry(F f){
  return detail::uncurry<F>(f);
}

namespace detail {

template<typename F, typename G>
struct compose :public thrust::unary_function<typename F::argument_type, typename G::result_type> {
  F _f;
  G _g;
  compose(F f, G g)
  :_f(f), _g(g){}
  __host__ __device__
  typename F::result_type operator()(const typename G::argument_type &x) const {
    return _f(_g(x));
  }
};

} // END detail

/*
  f * g
  b->c -> a->b -> a->c
*/
template<typename F, typename G>
detail::compose<F, G> compose(F f, G g){
  return detail::compose<F, G>(f, g);
}

namespace detail {

template<typename Out>
struct constant {
  Out _value;
  constant(Out value)
  :_value(value){} 
  template<typename In>
  __host__ __device__
  Out operator()(In in) const {
    return _value;
  }
};

} // END detail

template<typename Out>
detail::constant<Out> constant(Out value){
  return detail::constant<Out>(value);
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
  a -> b -> (a/b)::a
*/
template<typename A, typename B>
struct divides :public thrust::binary_function<A, B, A> {
  __host__ __device__
  A operator()(const A &x, const B &y) const {
    return x / y;
  }
};

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

// is this function used anywhere?
// I guess no.
template<typename A, typename B>
struct equal_to :public thrust::binary_function<A, B, bool> {
  __host__ __device__
  bool operator()(A a, B b) const {
    if(a==b){
      return true;
    }
    return false; 
  }
};

} // end thrusting
