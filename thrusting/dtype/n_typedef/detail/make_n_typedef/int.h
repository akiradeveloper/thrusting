
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<int>::type make_int2(int x0, int x1){
  return thrusting::make_tuple2<int>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<int>::type make_int3(int x0, int x1, int x2){
  return thrusting::make_tuple3<int>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<int>::type make_int4(int x0, int x1, int x2, int x3){
  return thrusting::make_tuple4<int>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<int>::type make_int5(int x0, int x1, int x2, int x3, int x4){
  return thrusting::make_tuple5<int>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<int>::type make_int6(int x0, int x1, int x2, int x3, int x4, int x5){
  return thrusting::make_tuple6<int>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<int>::type make_int7(int x0, int x1, int x2, int x3, int x4, int x5, int x6){
  return thrusting::make_tuple7<int>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<int>::type make_int8(int x0, int x1, int x2, int x3, int x4, int x5, int x6, int x7){
  return thrusting::make_tuple8<int>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<int>::type make_int9(int x0, int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8){
  return thrusting::make_tuple9<int>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
