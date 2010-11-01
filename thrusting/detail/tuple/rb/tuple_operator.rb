thisdir = File.expand_path File.dirname __FILE__ 

["get_tuple", "namespace", "template_type"].each do |s|
  require "thrusting/rb/#{s}"
end

def operator(n, op)
  input = (0...n).map { |i| "#{get_tuple(i, "x")}#{op}#{get_tuple(i, "y")}" }
"""
template<#{typename(0...n)}>
__host__ __device__
thrust::tuple<#{type(0...n)}> operator#{op}(const thrust::tuple<#{type(0...n)}> &x, const thrust::tuple<#{type(0...n)}> &y){
  return thrust::make_tuple(#{input.join(", ")});
}
"""
end

def all()
  ops = ['+', '-', '*', '/'] 
  code = (TUPLE_MIN..TUPLE_MAX).map { |i| ops.map { |op| operator(i, op) } }.join
"""
#pragma once
#include <thrusting/tuple.h>
#{operator_tuple(code)}
"""
end

if __FILE__ == $0
  $stdout << all()
end
