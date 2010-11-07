thisdir = File.expand_path File.dirname __FILE__ 

["get_tuple", "namespace", "template_type"].each do |s|
  require "thrusting/rb/#{s}"
end

def equality(n)
  bool = (0...n).map { |i| "(#{get_tuple(i, "x")} == #{get_tuple(i, "y")})" }.join(" && ")
"""
template<#{typename(0...n)}>
__host__ __device__
bool operator==(const thrust::tuple<#{type(0...n)}> &x, const thrust::tuple<#{type(0...n)}> &y){
  return #{bool};
}
template<#{typename(0...n)}>
__host__ __device__
bool operator!=(const thrust::tuple<#{type(0...n)}> &x, const thrust::tuple<#{type(0...n)}> &y){
  return ! (x==y);
}
"""
end

def all()
  code = (TUPLE_MIN..TUPLE_MAX).map { |i| equality(i) }.join
"""
#pragma once
#include <thrust/tuple.h>
#{operator_tuple(code)}
"""
end

if __FILE__ == $0
  $stdout << all()
end
