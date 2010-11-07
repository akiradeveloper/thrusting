
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<long>::type make_long2(long x0, long x1){
  return thrusting::make_tuple2<long>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<long>::type make_long3(long x0, long x1, long x2){
  return thrusting::make_tuple3<long>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<long>::type make_long4(long x0, long x1, long x2, long x3){
  return thrusting::make_tuple4<long>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<long>::type make_long5(long x0, long x1, long x2, long x3, long x4){
  return thrusting::make_tuple5<long>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<long>::type make_long6(long x0, long x1, long x2, long x3, long x4, long x5){
  return thrusting::make_tuple6<long>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<long>::type make_long7(long x0, long x1, long x2, long x3, long x4, long x5, long x6){
  return thrusting::make_tuple7<long>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<long>::type make_long8(long x0, long x1, long x2, long x3, long x4, long x5, long x6, long x7){
  return thrusting::make_tuple8<long>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<long>::type make_long9(long x0, long x1, long x2, long x3, long x4, long x5, long x6, long x7, long x8){
  return thrusting::make_tuple9<long>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
