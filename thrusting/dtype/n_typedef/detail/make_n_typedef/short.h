
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<short>::type make_short2(short x0, short x1){
  return thrusting::make_tuple2<short>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<short>::type make_short3(short x0, short x1, short x2){
  return thrusting::make_tuple3<short>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<short>::type make_short4(short x0, short x1, short x2, short x3){
  return thrusting::make_tuple4<short>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<short>::type make_short5(short x0, short x1, short x2, short x3, short x4){
  return thrusting::make_tuple5<short>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<short>::type make_short6(short x0, short x1, short x2, short x3, short x4, short x5){
  return thrusting::make_tuple6<short>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<short>::type make_short7(short x0, short x1, short x2, short x3, short x4, short x5, short x6){
  return thrusting::make_tuple7<short>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<short>::type make_short8(short x0, short x1, short x2, short x3, short x4, short x5, short x6, short x7){
  return thrusting::make_tuple8<short>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<short>::type make_short9(short x0, short x1, short x2, short x3, short x4, short x5, short x6, short x7, short x8){
  return thrusting::make_tuple9<short>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
