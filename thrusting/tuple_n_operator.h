
#pragma once
namespace thrusting {


template<typename T>
tuple2<T>::type operator*(tuple2<T>::type x, T y){
  return make_tuple2<T>(x.get<0>()*y, x.get<1>()*y);
}

template<typename T>
tupleN<T>::type operator*(T n, tupleN<T>::type x){
  return x * n;
}

template<typename T>
tuple2<T>::type operator/(tuple2<T>::type x, T y){
  return make_tuple2<T>(x.get<0>()/y, x.get<1>()/y);
}



template<typename T>
tuple3<T>::type operator*(tuple3<T>::type x, T y){
  return make_tuple3<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y);
}

template<typename T>
tupleN<T>::type operator*(T n, tupleN<T>::type x){
  return x * n;
}

template<typename T>
tuple3<T>::type operator/(tuple3<T>::type x, T y){
  return make_tuple3<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y);
}



template<typename T>
tuple4<T>::type operator*(tuple4<T>::type x, T y){
  return make_tuple4<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y);
}

template<typename T>
tupleN<T>::type operator*(T n, tupleN<T>::type x){
  return x * n;
}

template<typename T>
tuple4<T>::type operator/(tuple4<T>::type x, T y){
  return make_tuple4<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y);
}



template<typename T>
tuple5<T>::type operator*(tuple5<T>::type x, T y){
  return make_tuple5<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y, x.get<4>()*y);
}

template<typename T>
tupleN<T>::type operator*(T n, tupleN<T>::type x){
  return x * n;
}

template<typename T>
tuple5<T>::type operator/(tuple5<T>::type x, T y){
  return make_tuple5<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y, x.get<4>()/y);
}



template<typename T>
tuple6<T>::type operator*(tuple6<T>::type x, T y){
  return make_tuple6<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y, x.get<4>()*y, x.get<5>()*y);
}

template<typename T>
tupleN<T>::type operator*(T n, tupleN<T>::type x){
  return x * n;
}

template<typename T>
tuple6<T>::type operator/(tuple6<T>::type x, T y){
  return make_tuple6<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y, x.get<4>()/y, x.get<5>()/y);
}



template<typename T>
tuple7<T>::type operator*(tuple7<T>::type x, T y){
  return make_tuple7<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y, x.get<4>()*y, x.get<5>()*y, x.get<6>()*y);
}

template<typename T>
tupleN<T>::type operator*(T n, tupleN<T>::type x){
  return x * n;
}

template<typename T>
tuple7<T>::type operator/(tuple7<T>::type x, T y){
  return make_tuple7<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y, x.get<4>()/y, x.get<5>()/y, x.get<6>()/y);
}



template<typename T>
tuple8<T>::type operator*(tuple8<T>::type x, T y){
  return make_tuple8<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y, x.get<4>()*y, x.get<5>()*y, x.get<6>()*y, x.get<7>()*y);
}

template<typename T>
tupleN<T>::type operator*(T n, tupleN<T>::type x){
  return x * n;
}

template<typename T>
tuple8<T>::type operator/(tuple8<T>::type x, T y){
  return make_tuple8<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y, x.get<4>()/y, x.get<5>()/y, x.get<6>()/y, x.get<7>()/y);
}



template<typename T>
tuple9<T>::type operator*(tuple9<T>::type x, T y){
  return make_tuple9<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y, x.get<4>()*y, x.get<5>()*y, x.get<6>()*y, x.get<7>()*y, x.get<8>()*y);
}

template<typename T>
tupleN<T>::type operator*(T n, tupleN<T>::type x){
  return x * n;
}

template<typename T>
tuple9<T>::type operator/(tuple9<T>::type x, T y){
  return make_tuple9<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y, x.get<4>()/y, x.get<5>()/y, x.get<6>()/y, x.get<7>()/y, x.get<8>()/y);
}

 
}
