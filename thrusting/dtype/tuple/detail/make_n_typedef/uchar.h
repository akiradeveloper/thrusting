
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<unsigned char>::type make_uchar2(unsigned char x0, unsigned char x1){
  return thrusting::make_tuple2<unsigned char>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<unsigned char>::type make_uchar3(unsigned char x0, unsigned char x1, unsigned char x2){
  return thrusting::make_tuple3<unsigned char>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<unsigned char>::type make_uchar4(unsigned char x0, unsigned char x1, unsigned char x2, unsigned char x3){
  return thrusting::make_tuple4<unsigned char>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<unsigned char>::type make_uchar5(unsigned char x0, unsigned char x1, unsigned char x2, unsigned char x3, unsigned char x4){
  return thrusting::make_tuple5<unsigned char>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<unsigned char>::type make_uchar6(unsigned char x0, unsigned char x1, unsigned char x2, unsigned char x3, unsigned char x4, unsigned char x5){
  return thrusting::make_tuple6<unsigned char>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<unsigned char>::type make_uchar7(unsigned char x0, unsigned char x1, unsigned char x2, unsigned char x3, unsigned char x4, unsigned char x5, unsigned char x6){
  return thrusting::make_tuple7<unsigned char>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<unsigned char>::type make_uchar8(unsigned char x0, unsigned char x1, unsigned char x2, unsigned char x3, unsigned char x4, unsigned char x5, unsigned char x6, unsigned char x7){
  return thrusting::make_tuple8<unsigned char>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<unsigned char>::type make_uchar9(unsigned char x0, unsigned char x1, unsigned char x2, unsigned char x3, unsigned char x4, unsigned char x5, unsigned char x6, unsigned char x7, unsigned char x8){
  return thrusting::make_tuple9<unsigned char>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
