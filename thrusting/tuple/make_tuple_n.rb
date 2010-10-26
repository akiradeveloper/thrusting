thisdir = File.dirname(__FILE__)
require [thisdir, "get_tuple"].join "/"

"""
template<typename T>
typename tupleN<T>::type make_tupleN(T x0, T x1, ...){
  return thrust::make_tuple(x0, x1, ...);
}
"""

def tupleN(n)
arg = (0...n).map { |i| "T x#{i}" }
input = (0...n).map { |i| "x#{i}" }
"""
template<typename T>
__host__ __device__
typename tuple#{n}<T>::type make_tuple#{n}(#{arg.join(", ")}){
  return thrust::make_tuple(#{input.join(", ")});
}
"""
end

def all()
"""
#pragma once
#include \"tuple_n_typedef.h\"
namespace thrust {
#{(TUPLE_MIN..TUPLE_MAX).map { |i| tupleN(i) }.join("")}
}
"""
end

if __FILE__ == $0
  print all()
end
