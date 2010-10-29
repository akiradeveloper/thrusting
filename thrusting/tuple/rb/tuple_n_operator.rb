thisdir = File.expand_path File.dirname __FILE__ 

require ["thrusting/rb", "get_tuple"].join "/"
require ["thrusting/rb", "namespace"].join "/"

"""
template<typename T>
tupleN<T>::type operator*(tupleN<T>::type x, T n){
  return make_tupleN<T>(x.get<0>() * n, x.get<1>() * n, ...);
}
tupleN<T>::type operator*(T n, tupleN<T>::type x){
  return x * n;
}
tupleN<T>::type operator/(tupleN<T>::type x, T n){
  return make_tupleN<T>(x.get<0>() / n, ...);
}
"""

def _operator(n, op)
input = (0...n).map { |i| "#{get_tuple(i, "x")}#{op}y" }
"""
template<typename T>
__host__ __device__
typename tuple#{n}<T>::type operator#{op}(const typename tuple#{n}<T>::type &x, const T &y){
  return make_tuple#{n}<T>(#{input.join(", ")});
}
"""
end

def operator(n)
"""
#{_operator(n, "*")}
template<typename T>
__host__ __device__
typename tuple#{n}<T>::type operator*(const T &n, const typename tuple#{n}<T>::type &x){
  return x * n;
}
#{_operator(n, "/")}
"""
end

def all()
"""
#pragma once
#include \"make_tuple_n.h\"
#include \"tuple_n_typedef.h\"
#{operator_tuple((TUPLE_MIN..TUPLE_MAX).map { |i| operator(i) }.join)} 
"""
end

if __FILE__ == $0
  $stdout << all()
end
