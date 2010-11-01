thisdir = File.expand_path File.dirname __FILE__ 

["get_tuple", "namespace", "template_type"].each do |s|
  require "thrusting/rb/#{s}"
end

def gen_calc(op, n)
  (0...n).map { |i| get_tuple(i, "t") }.map { |x| "#{x} #{op} x" }.join(", ")
end

def gen_def(op, n)
"""
template<#{typename(0...n+1)}>
__host__ __device__
thrust::tuple<#{type(0...n)}> operator#{op}(const thrust::tuple<#{type(0...n)}> &t, const #{type(n..n)} &x){
  return thrust::make_tuple(#{gen_calc(op, n)});
}
"""
end

def gen_calc_reverse(op, n)
(0...n).map { |i| get_tuple(i, "t") }.map { |x| "x #{op} #{x}" }.join(", ")
end

def gen_def_reverse(op, n)
"""
template<#{typename(0...n+1)}>
thrust::tuple<#{type(0...n)}> operator#{op}(const #{type(n..n)} &x, const thrust::tuple<#{type(0...n)}> &t){
  return thrust::make_tuple(#{gen_calc_reverse(op, n)});
}
"""
end

def all()
#tuple_min = 1
tuple_min = TUPLE_MIN
#tuple_max = 1
tuple_max = TUPLE_MAX
"""
#pragma once
#include <thrust/tuple.h>
#{operator_tuple((tuple_min..tuple_max).map { |i| gen_def("*", i) }.join)} 
#{operator_tuple((tuple_min..tuple_max).map { |i| gen_def("/", i) }.join)} 
#{operator_tuple((tuple_min..tuple_max).map { |i| gen_def_reverse("*", i) }.join)} 
"""
end

if __FILE__ == $0
  $stdout << all()
end
