
#pragma once

#include "make_tuple_n.h"
#include "real_n_typedef.h"

using namespace thrusting {

real2 make_real2(real x0, real x1){
  return make_tuple2<real>(x0, x1);
}

real3 make_real3(real x0, real x1, real x2){
  return make_tuple3<real>(x0, x1, x2);
}

real4 make_real4(real x0, real x1, real x2, real x3){
  return make_tuple4<real>(x0, x1, x2, x3);
}

real5 make_real5(real x0, real x1, real x2, real x3, real x4){
  return make_tuple5<real>(x0, x1, x2, x3, x4);
}

real6 make_real6(real x0, real x1, real x2, real x3, real x4, real x5){
  return make_tuple6<real>(x0, x1, x2, x3, x4, x5);
}

real7 make_real7(real x0, real x1, real x2, real x3, real x4, real x5, real x6){
  return make_tuple7<real>(x0, x1, x2, x3, x4, x5, x6);
}

real8 make_real8(real x0, real x1, real x2, real x3, real x4, real x5, real x6, real x7){
  return make_tuple8<real>(x0, x1, x2, x3, x4, x5, x6, x7);
}

real9 make_real9(real x0, real x1, real x2, real x3, real x4, real x5, real x6, real x7, real x8){
  return make_tuple9<real>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
