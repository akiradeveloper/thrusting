
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<char>::type make_char2(char x0, char x1){
  return thrusting::make_tuple2<char>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<char>::type make_char3(char x0, char x1, char x2){
  return thrusting::make_tuple3<char>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<char>::type make_char4(char x0, char x1, char x2, char x3){
  return thrusting::make_tuple4<char>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<char>::type make_char5(char x0, char x1, char x2, char x3, char x4){
  return thrusting::make_tuple5<char>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<char>::type make_char6(char x0, char x1, char x2, char x3, char x4, char x5){
  return thrusting::make_tuple6<char>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<char>::type make_char7(char x0, char x1, char x2, char x3, char x4, char x5, char x6){
  return thrusting::make_tuple7<char>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<char>::type make_char8(char x0, char x1, char x2, char x3, char x4, char x5, char x6, char x7){
  return thrusting::make_tuple8<char>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<char>::type make_char9(char x0, char x1, char x2, char x3, char x4, char x5, char x6, char x7, char x8){
  return thrusting::make_tuple9<char>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
