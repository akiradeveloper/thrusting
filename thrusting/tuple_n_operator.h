
#pragma once
namespace thrusting {


template<typename T>
typename tuple2<T>::type operator*(const tuple2<T>::type &x, T y){
  return make_tuple2<T>(x.get<0>()*y, x.get<1>()*y);
}

template<typename T>
typename tuple2<T>::type operator*(T n, const tuple2<T>::type &x){
  return x * n;
}

template<typename T>
typename tuple2<T>::type operator/(const tuple2<T>::type &x, T y){
  return make_tuple2<T>(x.get<0>()/y, x.get<1>()/y);
}



template<typename T>
typename tuple3<T>::type operator*(const tuple3<T>::type &x, T y){
  return make_tuple3<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y);
}

template<typename T>
typename tuple3<T>::type operator*(T n, const tuple3<T>::type &x){
  return x * n;
}

template<typename T>
typename tuple3<T>::type operator/(const tuple3<T>::type &x, T y){
  return make_tuple3<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y);
}



template<typename T>
typename tuple4<T>::type operator*(const tuple4<T>::type &x, T y){
  return make_tuple4<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y);
}

template<typename T>
typename tuple4<T>::type operator*(T n, const tuple4<T>::type &x){
  return x * n;
}

template<typename T>
typename tuple4<T>::type operator/(const tuple4<T>::type &x, T y){
  return make_tuple4<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y);
}



template<typename T>
typename tuple5<T>::type operator*(const tuple5<T>::type &x, T y){
  return make_tuple5<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y, x.get<4>()*y);
}

template<typename T>
typename tuple5<T>::type operator*(T n, const tuple5<T>::type &x){
  return x * n;
}

template<typename T>
typename tuple5<T>::type operator/(const tuple5<T>::type &x, T y){
  return make_tuple5<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y, x.get<4>()/y);
}



template<typename T>
typename tuple6<T>::type operator*(const tuple6<T>::type &x, T y){
  return make_tuple6<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y, x.get<4>()*y, x.get<5>()*y);
}

template<typename T>
typename tuple6<T>::type operator*(T n, const tuple6<T>::type &x){
  return x * n;
}

template<typename T>
typename tuple6<T>::type operator/(const tuple6<T>::type &x, T y){
  return make_tuple6<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y, x.get<4>()/y, x.get<5>()/y);
}



template<typename T>
typename tuple7<T>::type operator*(const tuple7<T>::type &x, T y){
  return make_tuple7<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y, x.get<4>()*y, x.get<5>()*y, x.get<6>()*y);
}

template<typename T>
typename tuple7<T>::type operator*(T n, const tuple7<T>::type &x){
  return x * n;
}

template<typename T>
typename tuple7<T>::type operator/(const tuple7<T>::type &x, T y){
  return make_tuple7<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y, x.get<4>()/y, x.get<5>()/y, x.get<6>()/y);
}



template<typename T>
typename tuple8<T>::type operator*(const tuple8<T>::type &x, T y){
  return make_tuple8<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y, x.get<4>()*y, x.get<5>()*y, x.get<6>()*y, x.get<7>()*y);
}

template<typename T>
typename tuple8<T>::type operator*(T n, const tuple8<T>::type &x){
  return x * n;
}

template<typename T>
typename tuple8<T>::type operator/(const tuple8<T>::type &x, T y){
  return make_tuple8<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y, x.get<4>()/y, x.get<5>()/y, x.get<6>()/y, x.get<7>()/y);
}



template<typename T>
typename tuple9<T>::type operator*(const tuple9<T>::type &x, T y){
  return make_tuple9<T>(x.get<0>()*y, x.get<1>()*y, x.get<2>()*y, x.get<3>()*y, x.get<4>()*y, x.get<5>()*y, x.get<6>()*y, x.get<7>()*y, x.get<8>()*y);
}

template<typename T>
typename tuple9<T>::type operator*(T n, const tuple9<T>::type &x){
  return x * n;
}

template<typename T>
typename tuple9<T>::type operator/(const tuple9<T>::type &x, T y){
  return make_tuple9<T>(x.get<0>()/y, x.get<1>()/y, x.get<2>()/y, x.get<3>()/y, x.get<4>()/y, x.get<5>()/y, x.get<6>()/y, x.get<7>()/y, x.get<8>()/y);
}

 
}
