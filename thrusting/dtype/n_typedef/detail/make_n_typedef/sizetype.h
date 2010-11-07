
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<size_t>::type make_sizetype2(size_t x0, size_t x1){
  return thrusting::make_tuple2<size_t>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<size_t>::type make_sizetype3(size_t x0, size_t x1, size_t x2){
  return thrusting::make_tuple3<size_t>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<size_t>::type make_sizetype4(size_t x0, size_t x1, size_t x2, size_t x3){
  return thrusting::make_tuple4<size_t>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<size_t>::type make_sizetype5(size_t x0, size_t x1, size_t x2, size_t x3, size_t x4){
  return thrusting::make_tuple5<size_t>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<size_t>::type make_sizetype6(size_t x0, size_t x1, size_t x2, size_t x3, size_t x4, size_t x5){
  return thrusting::make_tuple6<size_t>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<size_t>::type make_sizetype7(size_t x0, size_t x1, size_t x2, size_t x3, size_t x4, size_t x5, size_t x6){
  return thrusting::make_tuple7<size_t>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<size_t>::type make_sizetype8(size_t x0, size_t x1, size_t x2, size_t x3, size_t x4, size_t x5, size_t x6, size_t x7){
  return thrusting::make_tuple8<size_t>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<size_t>::type make_sizetype9(size_t x0, size_t x1, size_t x2, size_t x3, size_t x4, size_t x5, size_t x6, size_t x7, size_t x8){
  return thrusting::make_tuple9<size_t>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
