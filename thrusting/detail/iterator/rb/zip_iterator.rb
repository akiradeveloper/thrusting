["tuple_min_max", "template_type"].each do |s|
  require "thrusting/rb/#{s}"
end

def make_zip_iterator(n)
"""
template<#{typename(0...n)}>
thrust::zip_iterator< thrust::tuple<#{type(0...n)}> > make_zip_iterator(#{type_arg(0...n)}){
  return thrust::make_zip_iterator(thrust::make_tuple(#{arg(0...n)}));
}
"""
end

def all()
  code = (TUPLE_MIN..TUPLE_MAX).map { |i| make_zip_iterator(i) }.join "\n"
"""
#pragma once
#include <thrust/iterator/zip_iterator.h>
#include <thrust/tuple.h>
namespace thrusting {
#{code}
}
"""
end

if __FILE__ == $0
  $stdout << all()
end
