
#pragma once
namespace thrusting {

__host__ __device__
typename thrusting::tuple2<float>::type make_float2(float x0, float x1){
  return thrusting::make_tuple2<float>(x0, x1);
}

__host__ __device__
typename thrusting::tuple3<float>::type make_float3(float x0, float x1, float x2){
  return thrusting::make_tuple3<float>(x0, x1, x2);
}

__host__ __device__
typename thrusting::tuple4<float>::type make_float4(float x0, float x1, float x2, float x3){
  return thrusting::make_tuple4<float>(x0, x1, x2, x3);
}

__host__ __device__
typename thrusting::tuple5<float>::type make_float5(float x0, float x1, float x2, float x3, float x4){
  return thrusting::make_tuple5<float>(x0, x1, x2, x3, x4);
}

__host__ __device__
typename thrusting::tuple6<float>::type make_float6(float x0, float x1, float x2, float x3, float x4, float x5){
  return thrusting::make_tuple6<float>(x0, x1, x2, x3, x4, x5);
}

__host__ __device__
typename thrusting::tuple7<float>::type make_float7(float x0, float x1, float x2, float x3, float x4, float x5, float x6){
  return thrusting::make_tuple7<float>(x0, x1, x2, x3, x4, x5, x6);
}

__host__ __device__
typename thrusting::tuple8<float>::type make_float8(float x0, float x1, float x2, float x3, float x4, float x5, float x6, float x7){
  return thrusting::make_tuple8<float>(x0, x1, x2, x3, x4, x5, x6, x7);
}

__host__ __device__
typename thrusting::tuple9<float>::type make_float9(float x0, float x1, float x2, float x3, float x4, float x5, float x6, float x7, float x8){
  return thrusting::make_tuple9<float>(x0, x1, x2, x3, x4, x5, x6, x7, x8);
}

}
