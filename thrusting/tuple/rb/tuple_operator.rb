thisdir = File.expand_path File.dirname __FILE__ 

require ["thrusting/rb", "get_tuple"].join "/"
require ["thrusting/rb", "namespace"].join "/"

"""
N : LENGTH 
op : Operator
template<typename T0, typename T1, ...>
thrust::tuple<T0, T1, ...> operator op (thrust::tuple<T0, T1, ...> x, thrust::tuple<T0, T1, ...> y){
  return thrust::make_tuple(x.get<0>() op y.get<0>(), ...);
}
"""
  
def operator(n, op)
arg = (0...n).map { |i| "typename T#{i}" }
arg2 = (0...n).map { |i| "T#{i}" }
input = (0...n).map { |i| "#{get_tuple(i, "x")}#{op}#{get_tuple(i, "y")}" }
"""
template<#{arg.join(", ")}>
__host__ __device__
thrust::tuple<#{arg2.join(", ")}> operator#{op}(const thrust::tuple<#{arg2.join(", ")}> &x, const thrust::tuple<#{arg2.join(", ")}> &y){
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
s = (0...n).map { |i| get_tuple(i, "x") }.join(" << \", \" << ")
"""
template<#{arg.join(", ")}>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<#{arg2.join(", ")}> &x){
  std::stringstream ss;
  ss << \"(\" << #{s} << \")\";
  os << ss.str();
  return os;
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
bool = (0...n).map { |i| "(#{get_tuple(i, "x")} == #{get_tuple(i, "y")})" }.join(" && ")
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
from = TUPLE_MIN
to = TUPLE_MAX
ops = ['+', '-', '*', '/'] 
operator = (from..to).map { |i| ops.map { |op| operator(i, op) } }.join
ostream = (from..to).map { |i| ostream(i) }.join
equality = (from..to).map { |i| equality(i) }.join
code =
"""
#{operator}
#{ostream}
#{equality}
"""

"""
#pragma once
#include <iostream>
#include <sstream>
#{operator_tuple(code)}
"""
end

if __FILE__ == $0
  $stdout << all()
end
