
#pragma once
namespace thrusting {

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
thrust::tuple<T4, T5> operator+(const thrust::tuple<T0, T1> &x, const thrust::tuple<T2, T3> &y){
  return thrust::make_tuple(x.get<0>()+y.get<0>(), x.get<1>()+y.get<1>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
thrust::tuple<T4, T5> operator-(const thrust::tuple<T0, T1> &x, const thrust::tuple<T2, T3> &y){
  return thrust::make_tuple(x.get<0>()-y.get<0>(), x.get<1>()-y.get<1>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
thrust::tuple<T4, T5> operator*(const thrust::tuple<T0, T1> &x, const thrust::tuple<T2, T3> &y){
  return thrust::make_tuple(x.get<0>()*y.get<0>(), x.get<1>()*y.get<1>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
thrust::tuple<T4, T5> operator/(const thrust::tuple<T0, T1> &x, const thrust::tuple<T2, T3> &y){
  return thrust::make_tuple(x.get<0>()/y.get<0>(), x.get<1>()/y.get<1>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
thrust::tuple<T6, T7, T8> operator+(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T3, T4, T5> &y){
  return thrust::make_tuple(x.get<0>()+y.get<0>(), x.get<1>()+y.get<1>(), x.get<2>()+y.get<2>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
thrust::tuple<T6, T7, T8> operator-(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T3, T4, T5> &y){
  return thrust::make_tuple(x.get<0>()-y.get<0>(), x.get<1>()-y.get<1>(), x.get<2>()-y.get<2>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
thrust::tuple<T6, T7, T8> operator*(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T3, T4, T5> &y){
  return thrust::make_tuple(x.get<0>()*y.get<0>(), x.get<1>()*y.get<1>(), x.get<2>()*y.get<2>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
thrust::tuple<T6, T7, T8> operator/(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T3, T4, T5> &y){
  return thrust::make_tuple(x.get<0>()/y.get<0>(), x.get<1>()/y.get<1>(), x.get<2>()/y.get<2>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
thrust::tuple<T8, T9, T10, T11> operator+(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T4, T5, T6, T7> &y){
  return thrust::make_tuple(x.get<0>()+y.get<0>(), x.get<1>()+y.get<1>(), x.get<2>()+y.get<2>(), x.get<3>()+y.get<3>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
thrust::tuple<T8, T9, T10, T11> operator-(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T4, T5, T6, T7> &y){
  return thrust::make_tuple(x.get<0>()-y.get<0>(), x.get<1>()-y.get<1>(), x.get<2>()-y.get<2>(), x.get<3>()-y.get<3>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
thrust::tuple<T8, T9, T10, T11> operator*(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T4, T5, T6, T7> &y){
  return thrust::make_tuple(x.get<0>()*y.get<0>(), x.get<1>()*y.get<1>(), x.get<2>()*y.get<2>(), x.get<3>()*y.get<3>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
thrust::tuple<T8, T9, T10, T11> operator/(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T4, T5, T6, T7> &y){
  return thrust::make_tuple(x.get<0>()/y.get<0>(), x.get<1>()/y.get<1>(), x.get<2>()/y.get<2>(), x.get<3>()/y.get<3>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
thrust::tuple<T10, T11, T12, T13, T14> operator+(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T5, T6, T7, T8, T9> &y){
  return thrust::make_tuple(x.get<0>()+y.get<0>(), x.get<1>()+y.get<1>(), x.get<2>()+y.get<2>(), x.get<3>()+y.get<3>(), x.get<4>()+y.get<4>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
thrust::tuple<T10, T11, T12, T13, T14> operator-(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T5, T6, T7, T8, T9> &y){
  return thrust::make_tuple(x.get<0>()-y.get<0>(), x.get<1>()-y.get<1>(), x.get<2>()-y.get<2>(), x.get<3>()-y.get<3>(), x.get<4>()-y.get<4>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
thrust::tuple<T10, T11, T12, T13, T14> operator*(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T5, T6, T7, T8, T9> &y){
  return thrust::make_tuple(x.get<0>()*y.get<0>(), x.get<1>()*y.get<1>(), x.get<2>()*y.get<2>(), x.get<3>()*y.get<3>(), x.get<4>()*y.get<4>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
thrust::tuple<T10, T11, T12, T13, T14> operator/(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T5, T6, T7, T8, T9> &y){
  return thrust::make_tuple(x.get<0>()/y.get<0>(), x.get<1>()/y.get<1>(), x.get<2>()/y.get<2>(), x.get<3>()/y.get<3>(), x.get<4>()/y.get<4>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
thrust::tuple<T12, T13, T14, T15, T16, T17> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T6, T7, T8, T9, T10, T11> &y){
  return thrust::make_tuple(x.get<0>()+y.get<0>(), x.get<1>()+y.get<1>(), x.get<2>()+y.get<2>(), x.get<3>()+y.get<3>(), x.get<4>()+y.get<4>(), x.get<5>()+y.get<5>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
thrust::tuple<T12, T13, T14, T15, T16, T17> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T6, T7, T8, T9, T10, T11> &y){
  return thrust::make_tuple(x.get<0>()-y.get<0>(), x.get<1>()-y.get<1>(), x.get<2>()-y.get<2>(), x.get<3>()-y.get<3>(), x.get<4>()-y.get<4>(), x.get<5>()-y.get<5>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
thrust::tuple<T12, T13, T14, T15, T16, T17> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T6, T7, T8, T9, T10, T11> &y){
  return thrust::make_tuple(x.get<0>()*y.get<0>(), x.get<1>()*y.get<1>(), x.get<2>()*y.get<2>(), x.get<3>()*y.get<3>(), x.get<4>()*y.get<4>(), x.get<5>()*y.get<5>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
thrust::tuple<T12, T13, T14, T15, T16, T17> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T6, T7, T8, T9, T10, T11> &y){
  return thrust::make_tuple(x.get<0>()/y.get<0>(), x.get<1>()/y.get<1>(), x.get<2>()/y.get<2>(), x.get<3>()/y.get<3>(), x.get<4>()/y.get<4>(), x.get<5>()/y.get<5>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
thrust::tuple<T14, T15, T16, T17, T18, T19, T20> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T7, T8, T9, T10, T11, T12, T13> &y){
  return thrust::make_tuple(x.get<0>()+y.get<0>(), x.get<1>()+y.get<1>(), x.get<2>()+y.get<2>(), x.get<3>()+y.get<3>(), x.get<4>()+y.get<4>(), x.get<5>()+y.get<5>(), x.get<6>()+y.get<6>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
thrust::tuple<T14, T15, T16, T17, T18, T19, T20> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T7, T8, T9, T10, T11, T12, T13> &y){
  return thrust::make_tuple(x.get<0>()-y.get<0>(), x.get<1>()-y.get<1>(), x.get<2>()-y.get<2>(), x.get<3>()-y.get<3>(), x.get<4>()-y.get<4>(), x.get<5>()-y.get<5>(), x.get<6>()-y.get<6>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
thrust::tuple<T14, T15, T16, T17, T18, T19, T20> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T7, T8, T9, T10, T11, T12, T13> &y){
  return thrust::make_tuple(x.get<0>()*y.get<0>(), x.get<1>()*y.get<1>(), x.get<2>()*y.get<2>(), x.get<3>()*y.get<3>(), x.get<4>()*y.get<4>(), x.get<5>()*y.get<5>(), x.get<6>()*y.get<6>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
thrust::tuple<T14, T15, T16, T17, T18, T19, T20> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T7, T8, T9, T10, T11, T12, T13> &y){
  return thrust::make_tuple(x.get<0>()/y.get<0>(), x.get<1>()/y.get<1>(), x.get<2>()/y.get<2>(), x.get<3>()/y.get<3>(), x.get<4>()/y.get<4>(), x.get<5>()/y.get<5>(), x.get<6>()/y.get<6>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23>
thrust::tuple<T16, T17, T18, T19, T20, T21, T22, T23> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T8, T9, T10, T11, T12, T13, T14, T15> &y){
  return thrust::make_tuple(x.get<0>()+y.get<0>(), x.get<1>()+y.get<1>(), x.get<2>()+y.get<2>(), x.get<3>()+y.get<3>(), x.get<4>()+y.get<4>(), x.get<5>()+y.get<5>(), x.get<6>()+y.get<6>(), x.get<7>()+y.get<7>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23>
thrust::tuple<T16, T17, T18, T19, T20, T21, T22, T23> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T8, T9, T10, T11, T12, T13, T14, T15> &y){
  return thrust::make_tuple(x.get<0>()-y.get<0>(), x.get<1>()-y.get<1>(), x.get<2>()-y.get<2>(), x.get<3>()-y.get<3>(), x.get<4>()-y.get<4>(), x.get<5>()-y.get<5>(), x.get<6>()-y.get<6>(), x.get<7>()-y.get<7>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23>
thrust::tuple<T16, T17, T18, T19, T20, T21, T22, T23> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T8, T9, T10, T11, T12, T13, T14, T15> &y){
  return thrust::make_tuple(x.get<0>()*y.get<0>(), x.get<1>()*y.get<1>(), x.get<2>()*y.get<2>(), x.get<3>()*y.get<3>(), x.get<4>()*y.get<4>(), x.get<5>()*y.get<5>(), x.get<6>()*y.get<6>(), x.get<7>()*y.get<7>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23>
thrust::tuple<T16, T17, T18, T19, T20, T21, T22, T23> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T8, T9, T10, T11, T12, T13, T14, T15> &y){
  return thrust::make_tuple(x.get<0>()/y.get<0>(), x.get<1>()/y.get<1>(), x.get<2>()/y.get<2>(), x.get<3>()/y.get<3>(), x.get<4>()/y.get<4>(), x.get<5>()/y.get<5>(), x.get<6>()/y.get<6>(), x.get<7>()/y.get<7>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26>
thrust::tuple<T18, T19, T20, T21, T22, T23, T24, T25, T26> operator+(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T9, T10, T11, T12, T13, T14, T15, T16, T17> &y){
  return thrust::make_tuple(x.get<0>()+y.get<0>(), x.get<1>()+y.get<1>(), x.get<2>()+y.get<2>(), x.get<3>()+y.get<3>(), x.get<4>()+y.get<4>(), x.get<5>()+y.get<5>(), x.get<6>()+y.get<6>(), x.get<7>()+y.get<7>(), x.get<8>()+y.get<8>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26>
thrust::tuple<T18, T19, T20, T21, T22, T23, T24, T25, T26> operator-(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T9, T10, T11, T12, T13, T14, T15, T16, T17> &y){
  return thrust::make_tuple(x.get<0>()-y.get<0>(), x.get<1>()-y.get<1>(), x.get<2>()-y.get<2>(), x.get<3>()-y.get<3>(), x.get<4>()-y.get<4>(), x.get<5>()-y.get<5>(), x.get<6>()-y.get<6>(), x.get<7>()-y.get<7>(), x.get<8>()-y.get<8>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26>
thrust::tuple<T18, T19, T20, T21, T22, T23, T24, T25, T26> operator*(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T9, T10, T11, T12, T13, T14, T15, T16, T17> &y){
  return thrust::make_tuple(x.get<0>()*y.get<0>(), x.get<1>()*y.get<1>(), x.get<2>()*y.get<2>(), x.get<3>()*y.get<3>(), x.get<4>()*y.get<4>(), x.get<5>()*y.get<5>(), x.get<6>()*y.get<6>(), x.get<7>()*y.get<7>(), x.get<8>()*y.get<8>());
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26>
thrust::tuple<T18, T19, T20, T21, T22, T23, T24, T25, T26> operator/(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T9, T10, T11, T12, T13, T14, T15, T16, T17> &y){
  return thrust::make_tuple(x.get<0>()/y.get<0>(), x.get<1>()/y.get<1>(), x.get<2>()/y.get<2>(), x.get<3>()/y.get<3>(), x.get<4>()/y.get<4>(), x.get<5>()/y.get<5>(), x.get<6>()/y.get<6>(), x.get<7>()/y.get<7>(), x.get<8>()/y.get<8>());
}


template<typename T0, typename T1>
std::stream &operator<<(ostream &os, const thrust::tuple<T0, T1> &x){
  std::string s;
  s = '(' + x.get<0>() + ',' + x.get<1>() + ')';
  os << s;
  return s;
}

template<typename T0, typename T1, typename T2>
std::stream &operator<<(ostream &os, const thrust::tuple<T0, T1, T2> &x){
  std::string s;
  s = '(' + x.get<0>() + ',' + x.get<1>() + ',' + x.get<2>() + ')';
  os << s;
  return s;
}

template<typename T0, typename T1, typename T2, typename T3>
std::stream &operator<<(ostream &os, const thrust::tuple<T0, T1, T2, T3> &x){
  std::string s;
  s = '(' + x.get<0>() + ',' + x.get<1>() + ',' + x.get<2>() + ',' + x.get<3>() + ')';
  os << s;
  return s;
}

template<typename T0, typename T1, typename T2, typename T3, typename T4>
std::stream &operator<<(ostream &os, const thrust::tuple<T0, T1, T2, T3, T4> &x){
  std::string s;
  s = '(' + x.get<0>() + ',' + x.get<1>() + ',' + x.get<2>() + ',' + x.get<3>() + ',' + x.get<4>() + ')';
  os << s;
  return s;
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
std::stream &operator<<(ostream &os, const thrust::tuple<T0, T1, T2, T3, T4, T5> &x){
  std::string s;
  s = '(' + x.get<0>() + ',' + x.get<1>() + ',' + x.get<2>() + ',' + x.get<3>() + ',' + x.get<4>() + ',' + x.get<5>() + ')';
  os << s;
  return s;
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
std::stream &operator<<(ostream &os, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x){
  std::string s;
  s = '(' + x.get<0>() + ',' + x.get<1>() + ',' + x.get<2>() + ',' + x.get<3>() + ',' + x.get<4>() + ',' + x.get<5>() + ',' + x.get<6>() + ')';
  os << s;
  return s;
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
std::stream &operator<<(ostream &os, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x){
  std::string s;
  s = '(' + x.get<0>() + ',' + x.get<1>() + ',' + x.get<2>() + ',' + x.get<3>() + ',' + x.get<4>() + ',' + x.get<5>() + ',' + x.get<6>() + ',' + x.get<7>() + ')';
  os << s;
  return s;
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
std::stream &operator<<(ostream &os, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x){
  std::string s;
  s = '(' + x.get<0>() + ',' + x.get<1>() + ',' + x.get<2>() + ',' + x.get<3>() + ',' + x.get<4>() + ',' + x.get<5>() + ',' + x.get<6>() + ',' + x.get<7>() + ',' + x.get<8>() + ')';
  os << s;
  return s;
}


template<typename T0, typename T1>
bool operator==(const thrust::tuple<T0, T1> &x, const thrust::tuple<T0, T1> &y){
  return (x.get<0>() == y.get<0>()) && (x.get<1>() == y.get<1>());
}
template<typename T0, typename T1>
bool operator!=(const thrust::tuple<T0, T1> &x, const thrust::tuple<T0, T1> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2>
bool operator==(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T0, T1, T2> &y){
  return (x.get<0>() == y.get<0>()) && (x.get<1>() == y.get<1>()) && (x.get<2>() == y.get<2>());
}
template<typename T0, typename T1, typename T2>
bool operator!=(const thrust::tuple<T0, T1, T2> &x, const thrust::tuple<T0, T1, T2> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3>
bool operator==(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T0, T1, T2, T3> &y){
  return (x.get<0>() == y.get<0>()) && (x.get<1>() == y.get<1>()) && (x.get<2>() == y.get<2>()) && (x.get<3>() == y.get<3>());
}
template<typename T0, typename T1, typename T2, typename T3>
bool operator!=(const thrust::tuple<T0, T1, T2, T3> &x, const thrust::tuple<T0, T1, T2, T3> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4>
bool operator==(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T0, T1, T2, T3, T4> &y){
  return (x.get<0>() == y.get<0>()) && (x.get<1>() == y.get<1>()) && (x.get<2>() == y.get<2>()) && (x.get<3>() == y.get<3>()) && (x.get<4>() == y.get<4>());
}
template<typename T0, typename T1, typename T2, typename T3, typename T4>
bool operator!=(const thrust::tuple<T0, T1, T2, T3, T4> &x, const thrust::tuple<T0, T1, T2, T3, T4> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
bool operator==(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5> &y){
  return (x.get<0>() == y.get<0>()) && (x.get<1>() == y.get<1>()) && (x.get<2>() == y.get<2>()) && (x.get<3>() == y.get<3>()) && (x.get<4>() == y.get<4>()) && (x.get<5>() == y.get<5>());
}
template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
bool operator!=(const thrust::tuple<T0, T1, T2, T3, T4, T5> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
bool operator==(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &y){
  return (x.get<0>() == y.get<0>()) && (x.get<1>() == y.get<1>()) && (x.get<2>() == y.get<2>()) && (x.get<3>() == y.get<3>()) && (x.get<4>() == y.get<4>()) && (x.get<5>() == y.get<5>()) && (x.get<6>() == y.get<6>());
}
template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
bool operator!=(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
bool operator==(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &y){
  return (x.get<0>() == y.get<0>()) && (x.get<1>() == y.get<1>()) && (x.get<2>() == y.get<2>()) && (x.get<3>() == y.get<3>()) && (x.get<4>() == y.get<4>()) && (x.get<5>() == y.get<5>()) && (x.get<6>() == y.get<6>()) && (x.get<7>() == y.get<7>());
}
template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
bool operator!=(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7> &y){
  return ! (x==y);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
bool operator==(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &y){
  return (x.get<0>() == y.get<0>()) && (x.get<1>() == y.get<1>()) && (x.get<2>() == y.get<2>()) && (x.get<3>() == y.get<3>()) && (x.get<4>() == y.get<4>()) && (x.get<5>() == y.get<5>()) && (x.get<6>() == y.get<6>()) && (x.get<7>() == y.get<7>()) && (x.get<8>() == y.get<8>());
}
template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
bool operator!=(const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &x, const thrust::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> &y){
  return ! (x==y);
}

}
