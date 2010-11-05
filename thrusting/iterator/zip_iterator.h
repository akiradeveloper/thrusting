
#pragma once
#include <thrust/iterator/zip_iterator.h>
#include <thrust/tuple.h>
namespace thrusting {

template<typename X0, typename X1>
thrust::zip_iterator< thrust::tuple<X0, X1> > make_zip_iterator(X0 x0, X1 x1){
  return thrust::make_zip_iterator(thrust::make_tuple(x0, x1));
}


template<typename X0, typename X1, typename X2>
thrust::zip_iterator< thrust::tuple<X0, X1, X2> > make_zip_iterator(X0 x0, X1 x1, X2 x2){
  return thrust::make_zip_iterator(thrust::make_tuple(x0, x1, x2));
}


template<typename X0, typename X1, typename X2, typename X3>
thrust::zip_iterator< thrust::tuple<X0, X1, X2, X3> > make_zip_iterator(X0 x0, X1 x1, X2 x2, X3 x3){
  return thrust::make_zip_iterator(thrust::make_tuple(x0, x1, x2, x3));
}


template<typename X0, typename X1, typename X2, typename X3, typename X4>
thrust::zip_iterator< thrust::tuple<X0, X1, X2, X3, X4> > make_zip_iterator(X0 x0, X1 x1, X2 x2, X3 x3, X4 x4){
  return thrust::make_zip_iterator(thrust::make_tuple(x0, x1, x2, x3, x4));
}


template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5>
thrust::zip_iterator< thrust::tuple<X0, X1, X2, X3, X4, X5> > make_zip_iterator(X0 x0, X1 x1, X2 x2, X3 x3, X4 x4, X5 x5){
  return thrust::make_zip_iterator(thrust::make_tuple(x0, x1, x2, x3, x4, x5));
}


template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6>
thrust::zip_iterator< thrust::tuple<X0, X1, X2, X3, X4, X5, X6> > make_zip_iterator(X0 x0, X1 x1, X2 x2, X3 x3, X4 x4, X5 x5, X6 x6){
  return thrust::make_zip_iterator(thrust::make_tuple(x0, x1, x2, x3, x4, x5, x6));
}


template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7>
thrust::zip_iterator< thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7> > make_zip_iterator(X0 x0, X1 x1, X2 x2, X3 x3, X4 x4, X5 x5, X6 x6, X7 x7){
  return thrust::make_zip_iterator(thrust::make_tuple(x0, x1, x2, x3, x4, x5, x6, x7));
}


template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7, typename X8>
thrust::zip_iterator< thrust::tuple<X0, X1, X2, X3, X4, X5, X6, X7, X8> > make_zip_iterator(X0 x0, X1 x1, X2 x2, X3 x3, X4 x4, X5 x5, X6 x6, X7 x7, X8 x8){
  return thrust::make_zip_iterator(thrust::make_tuple(x0, x1, x2, x3, x4, x5, x6, x7, x8));
}

}
