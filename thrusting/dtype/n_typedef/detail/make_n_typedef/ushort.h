
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<unsigned short>::type make_ushort2(unsigned short x0, unsigned short x1){
  return thrusting::make_tuple2<unsigned short>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<unsigned short>::type make_ushort3(unsigned short x0, unsigned short x1, unsigned short x2){
  return thrusting::make_tuple3<unsigned short>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<unsigned short>::type make_ushort4(unsigned short x0, unsigned short x1, unsigned short x2, unsigned short x3){
  return thrusting::make_tuple4<unsigned short>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<unsigned short>::type make_ushort5(unsigned short x0, unsigned short x1, unsigned short x2, unsigned short x3, unsigned short x4){
  return thrusting::make_tuple5<unsigned short>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<unsigned short>::type make_ushort6(unsigned short x0, unsigned short x1, unsigned short x2, unsigned short x3, unsigned short x4, unsigned short x5){
  return thrusting::make_tuple6<unsigned short>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<unsigned short>::type make_ushort7(unsigned short x0, unsigned short x1, unsigned short x2, unsigned short x3, unsigned short x4, unsigned short x5, unsigned short x6){
  return thrusting::make_tuple7<unsigned short>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<unsigned short>::type make_ushort8(unsigned short x0, unsigned short x1, unsigned short x2, unsigned short x3, unsigned short x4, unsigned short x5, unsigned short x6, unsigned short x7){
  return thrusting::make_tuple8<unsigned short>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<unsigned short>::type make_ushort9(unsigned short x0, unsigned short x1, unsigned short x2, unsigned short x3, unsigned short x4, unsigned short x5, unsigned short x6, unsigned short x7, unsigned short x8){
  return thrusting::make_tuple9<unsigned short>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
