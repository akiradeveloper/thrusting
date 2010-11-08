
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<real>::type make_real2(real x0, real x1){
  return thrusting::make_tuple2<real>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<real>::type make_real3(real x0, real x1, real x2){
  return thrusting::make_tuple3<real>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<real>::type make_real4(real x0, real x1, real x2, real x3){
  return thrusting::make_tuple4<real>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<real>::type make_real5(real x0, real x1, real x2, real x3, real x4){
  return thrusting::make_tuple5<real>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<real>::type make_real6(real x0, real x1, real x2, real x3, real x4, real x5){
  return thrusting::make_tuple6<real>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<real>::type make_real7(real x0, real x1, real x2, real x3, real x4, real x5, real x6){
  return thrusting::make_tuple7<real>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<real>::type make_real8(real x0, real x1, real x2, real x3, real x4, real x5, real x6, real x7){
  return thrusting::make_tuple8<real>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<real>::type make_real9(real x0, real x1, real x2, real x3, real x4, real x5, real x6, real x7, real x8){
  return thrusting::make_tuple9<real>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
