"""
N : LENGTH 
op : Operator
template<typename T0, typename T1, ...>
thrust::tuple<T0, T1, ...> operator op (thrust::tuple<T0, T1, ...> x, thrust::tuple<T0, T1, ...> y){
  return thrust::make_tuple(x.get<0>() op y.get<0>(), ...);
}
"""
  
def operator(n, op)
arg = (0...n*3).map { |i| "typename T#{i}" }
arg2 = (0...n).map { |i| "T#{i}" }
arg3 = (n...n*2).map { |i| "T#{i}" }
arg4 = (n*2...n*3).map { |i| "T#{i}" }
input = (0...n).map { |i| "x.get<#{i}>()#{op}y.get<#{i}>()" }
"""
template<#{arg.join(", ")}>
__host__ __device__
thrust::tuple<#{arg4.join(", ")}> operator#{op}(const thrust::tuple<#{arg2.join(", ")}> &x, const thrust::tuple<#{arg3.join(", ")}> &y){
  return thrust::make_tuple(#{input.join(", ")});
}
"""
end

"""
template<typename T0, typename T1, ...>
std::stream &operator<<(const std::ostream &os, thrust::tuple<T0, T1, ...> x){
}
"""

def ostream(n)
arg = (0...n).map { |i| "typename T#{i}" }
arg2 = (0...n).map { |i| "T#{i}" }
s = (0...n).map { |i| "x.get<#{i}>()" }.join(" + ',' + ")
"""
template<#{arg.join(", ")}>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<#{arg2.join(", ")}> &x){
  std::string s;
  s = '(' + #{s} + ')';
  os << s;
  return s;
}
"""
end

"""
template<typename T0, ...>
__host__ __device__
bool operator==(const thrust::tuple<T0, ...> x, const thrust::tuple<T0, ...> y){
  return x.get<0>() == y.get<1>() && ...;
}
bool operator!=
  return ! (x==y);
}
"""

def equality(n)
arg = (0...n).map { |i| "typename T#{i}" }
arg2 = (0...n).map { |i| "T#{i}" }
bool = (0...n).map { |i| "(x.get<#{i}>() == y.get<#{i}>())" }.join(" && ")
"""
template<#{arg.join(", ")}>
__host__ __device__
bool operator==(const thrust::tuple<#{arg2.join(", ")}> &x, const thrust::tuple<#{arg2.join(", ")}> &y){
  return #{bool};
}
template<#{arg.join(", ")}>
__host__ __device__
bool operator!=(const thrust::tuple<#{arg2.join(", ")}> &x, const thrust::tuple<#{arg2.join(", ")}> &y){
  return ! (x==y);
}
"""
end

def all()
from = 2
to = 9
ops = ['+', '-', '*', '/'] 
operator = (from..to).map { |i| ops.map { |op| operator(i, op) } }.join
ostream = (from..to).map { |i| ostream(i) }.join
equality = (from..to).map { |i| equality(i) }.join
"""
#include <iostream>
#pragma once
namespace thrusting {
#{operator}
#{ostream}
#{equality}
}
"""
end

if __FILE__ == $0
  print all()
end
