
#pragma once
#include <thrust/tuple.h>
namespace thrust {

template<typename T>
struct tuple2 {
  typedef thrust::tuple<T, T> type;
};

template<typename T>
struct tuple3 {
  typedef thrust::tuple<T, T, T> type;
};

template<typename T>
struct tuple4 {
  typedef thrust::tuple<T, T, T, T> type;
};

template<typename T>
struct tuple5 {
  typedef thrust::tuple<T, T, T, T, T> type;
};

template<typename T>
struct tuple6 {
  typedef thrust::tuple<T, T, T, T, T, T> type;
};

template<typename T>
struct tuple7 {
  typedef thrust::tuple<T, T, T, T, T, T, T> type;
};

template<typename T>
struct tuple8 {
  typedef thrust::tuple<T, T, T, T, T, T, T, T> type;
};

template<typename T>
struct tuple9 {
  typedef thrust::tuple<T, T, T, T, T, T, T, T, T> type;
};

}
