thisdir = File.expand_path File.dirname __FILE__ 

require ["thrusting/rb", "get_tuple"].join "/"
require ["thrusting/rb", "namespace"].join "/"

def gen_calc(op, n)
(0...n).map { |i| get_tuple(i, "t") }.map { |x| "#{x} #{op} x" }.join(", ")
end

def gen_def(op, n)
_type_tuple = (0...n).map { |i| "X#{i}" }
_type_value = "X#{n}"
type_value = _type_value
type_tuple = 
type_all = (_type_tuple + [_type_value]).map { |x| "typename #{x}" }
result = gen_calc(op, n)
"""
template<#{type_all.join(", ")}>
thrust::tuple<#{_type_tuple.join(", ")}> operator#{op}(const thrust::tuple<#{_type_tuple.join(", ")}> &t, const #{_type_value} &x){
  return thrust::make_tuple(#{result});
}
"""
end

def gen_calc_reverse(op, n)
(0...n).map { |i| get_tuple(i, "t") }.map { |x| "x #{op} #{x}" }.join(", ")
end

def gen_def_reverse(op, n)
_type_tuple = (0...n).map { |i| "X#{i}" }
_type_value = "X#{n}"
type_value = _type_value
type_tuple = 
type_all = (_type_tuple + [_type_value]).map { |x| "typename #{x}" }
result = gen_calc_reverse(op, n)
"""
template<#{type_all.join(", ")}>
thrust::tuple<#{_type_tuple.join(", ")}> operator#{op}(const #{_type_value} &x, const thrust::tuple<#{_type_tuple.join(", ")}> &t){
  return thrust::make_tuple(#{result});
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
