
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<double>::type make_double2(double x0, double x1){
  return thrusting::make_tuple2<double>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<double>::type make_double3(double x0, double x1, double x2){
  return thrusting::make_tuple3<double>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<double>::type make_double4(double x0, double x1, double x2, double x3){
  return thrusting::make_tuple4<double>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<double>::type make_double5(double x0, double x1, double x2, double x3, double x4){
  return thrusting::make_tuple5<double>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<double>::type make_double6(double x0, double x1, double x2, double x3, double x4, double x5){
  return thrusting::make_tuple6<double>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<double>::type make_double7(double x0, double x1, double x2, double x3, double x4, double x5, double x6){
  return thrusting::make_tuple7<double>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<double>::type make_double8(double x0, double x1, double x2, double x3, double x4, double x5, double x6, double x7){
  return thrusting::make_tuple8<double>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<double>::type make_double9(double x0, double x1, double x2, double x3, double x4, double x5, double x6, double x7, double x8){
  return thrusting::make_tuple9<double>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
