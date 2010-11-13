
#pragma once
#include <thrusting/tuple.h>
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<long long>::type make_longlong2(long long x0, long long x1){
  return thrusting::make_tuple2<long long>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<long long>::type make_longlong3(long long x0, long long x1, long long x2){
  return thrusting::make_tuple3<long long>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<long long>::type make_longlong4(long long x0, long long x1, long long x2, long long x3){
  return thrusting::make_tuple4<long long>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<long long>::type make_longlong5(long long x0, long long x1, long long x2, long long x3, long long x4){
  return thrusting::make_tuple5<long long>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<long long>::type make_longlong6(long long x0, long long x1, long long x2, long long x3, long long x4, long long x5){
  return thrusting::make_tuple6<long long>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<long long>::type make_longlong7(long long x0, long long x1, long long x2, long long x3, long long x4, long long x5, long long x6){
  return thrusting::make_tuple7<long long>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<long long>::type make_longlong8(long long x0, long long x1, long long x2, long long x3, long long x4, long long x5, long long x6, long long x7){
  return thrusting::make_tuple8<long long>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<long long>::type make_longlong9(long long x0, long long x1, long long x2, long long x3, long long x4, long long x5, long long x6, long long x7, long long x8){
  return thrusting::make_tuple9<long long>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
