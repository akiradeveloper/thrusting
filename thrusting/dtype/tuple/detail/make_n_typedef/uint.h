
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<unsigned int>::type make_uint2(unsigned int x0, unsigned int x1){
  return thrusting::make_tuple2<unsigned int>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<unsigned int>::type make_uint3(unsigned int x0, unsigned int x1, unsigned int x2){
  return thrusting::make_tuple3<unsigned int>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<unsigned int>::type make_uint4(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3){
  return thrusting::make_tuple4<unsigned int>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<unsigned int>::type make_uint5(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3, unsigned int x4){
  return thrusting::make_tuple5<unsigned int>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<unsigned int>::type make_uint6(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3, unsigned int x4, unsigned int x5){
  return thrusting::make_tuple6<unsigned int>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<unsigned int>::type make_uint7(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3, unsigned int x4, unsigned int x5, unsigned int x6){
  return thrusting::make_tuple7<unsigned int>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<unsigned int>::type make_uint8(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3, unsigned int x4, unsigned int x5, unsigned int x6, unsigned int x7){
  return thrusting::make_tuple8<unsigned int>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<unsigned int>::type make_uint9(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3, unsigned int x4, unsigned int x5, unsigned int x6, unsigned int x7, unsigned int x8){
  return thrusting::make_tuple9<unsigned int>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
