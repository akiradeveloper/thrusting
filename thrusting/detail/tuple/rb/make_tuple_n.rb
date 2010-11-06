thisdir = File.expand_path File.dirname __FILE__ 

["get_tuple", "template_type"].each do |s|
  require "thrusting/rb/#{s}"
end

def tupleN(n)
  arg = (0...n).map { |i| "T x#{i}" }
  input = (0...n).map { |i| "x#{i}" }
"""
template<typename T>
__host__ __device__
typename tuple#{n}<T>::type make_tuple#{n}(#{explicit_type_arg("T", 0...n)}){
  return thrust::make_tuple(#{arg(0...n)});
}
"""
end

def all()
  code = (TUPLE_MIN..TUPLE_MAX).map { |i| tupleN(i) }.join("")
"""
#pragma once
#include <thrusting/tuple.h>
namespace thrusting {
#{code}
}
"""
end

if __FILE__ == $0
  $stdout << all()
end
