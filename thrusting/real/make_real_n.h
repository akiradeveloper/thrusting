#pragma once
#include "make_tuple_n.h"
#include "real_n_typedef.h"
namespace thrust {

__host__ __device__
real2 make_real2(real x0, real x1){
  return make_tuple2<real>(x0, x1);
}

__host__ __device__
real3 make_real3(real x0, real x1, real x2){
  return make_tuple3<real>(x0, x1, x2);
}

__host__ __device__
real4 make_real4(real x0, real x1, real x2, real x3){
  return make_tuple4<real>(x0, x1, x2, x3);
}

__host__ __device__
real5 make_real5(real x0, real x1, real x2, real x3, real x4){
  return make_tuple5<real>(x0, x1, x2, x3, x4);
}

__host__ __device__
real6 make_real6(real x0, real x1, real x2, real x3, real x4, real x5){
  return make_tuple6<real>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
real7 make_real7(real x0, real x1, real x2, real x3, real x4, real x5, real x6){
  return make_tuple7<real>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
real8 make_real8(real x0, real x1, real x2, real x3, real x4, real x5, real x6, real x7){
  return make_tuple8<real>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
real9 make_real9(real x0, real x1, real x2, real x3, real x4, real x5, real x6, real x7, real x8){
  return make_tuple9<real>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
