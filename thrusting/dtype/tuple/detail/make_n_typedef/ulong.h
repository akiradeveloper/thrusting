
#pragma once
#include <thrusting/tuple.h>
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<unsigned long>::type make_ulong2(unsigned long x0, unsigned long x1){
  return thrusting::make_tuple2<unsigned long>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<unsigned long>::type make_ulong3(unsigned long x0, unsigned long x1, unsigned long x2){
  return thrusting::make_tuple3<unsigned long>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<unsigned long>::type make_ulong4(unsigned long x0, unsigned long x1, unsigned long x2, unsigned long x3){
  return thrusting::make_tuple4<unsigned long>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<unsigned long>::type make_ulong5(unsigned long x0, unsigned long x1, unsigned long x2, unsigned long x3, unsigned long x4){
  return thrusting::make_tuple5<unsigned long>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<unsigned long>::type make_ulong6(unsigned long x0, unsigned long x1, unsigned long x2, unsigned long x3, unsigned long x4, unsigned long x5){
  return thrusting::make_tuple6<unsigned long>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<unsigned long>::type make_ulong7(unsigned long x0, unsigned long x1, unsigned long x2, unsigned long x3, unsigned long x4, unsigned long x5, unsigned long x6){
  return thrusting::make_tuple7<unsigned long>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<unsigned long>::type make_ulong8(unsigned long x0, unsigned long x1, unsigned long x2, unsigned long x3, unsigned long x4, unsigned long x5, unsigned long x6, unsigned long x7){
  return thrusting::make_tuple8<unsigned long>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<unsigned long>::type make_ulong9(unsigned long x0, unsigned long x1, unsigned long x2, unsigned long x3, unsigned long x4, unsigned long x5, unsigned long x6, unsigned long x7, unsigned long x8){
  return thrusting::make_tuple9<unsigned long>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
