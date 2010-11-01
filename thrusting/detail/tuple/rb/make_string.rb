thisdir = File.expand_path File.dirname __FILE__

["tuple_min_max", "get_tuple", "template_type"].each do |s|
  require "thrusting/rb/#{s}"
end

def write_function(n)
  s = (0...n).map { |i| get_tuple(i, "t") }.join(" << \", \" << ")
"""
template<#{typename(0...n)}>
std::string make_string(const thrust::tuple<#{type(0...n)}> &t){
  std::stringstream ss;
  ss << \"(\" << #{s} << \")\";
  return ss.str();
}
"""
end

def all()
  code = (TUPLE_MIN..TUPLE_MAX).map { |i| write_function(i) }.join "\n"
"""
#pragma once
#include <thrust/tuple.h>
#include <sstream>
#include <string>
namespace thrusting {
#{code}
}
"""
end

if __FILE__ == $0
  $stdout << all()
end
