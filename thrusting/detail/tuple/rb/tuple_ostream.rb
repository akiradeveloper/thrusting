thisdir = File.expand_path File.dirname __FILE__ 

["get_tuple", "namespace", "template_type"].each do |s|
  require "thrusting/rb/#{s}"
end

def ostream(n)
"""
template<#{typename(0...n)}>
std::ostream &operator<<(std::ostream &os, const thrust::tuple<#{type(0...n)}> &t){
  os << thrusting::make_string(t);
  return os;
}
"""
end

def all()
  code = (TUPLE_MIN..TUPLE_MAX).map { |i| ostream(i) }.join
"""
#pragma once
#include <thrusting/tuple.h>
#include <iostream>
#{operator_tuple(code)}
"""
end

if __FILE__ == $0
  $stdout << all()
end
