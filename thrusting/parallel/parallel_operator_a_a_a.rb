thisdir = File.expand_path(File.dirname(__FILE__))

"""
op : op charcter for example '+'
functor : for example 'plus'

void operator(op)=(parallel<A> xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head();
  thrust::transform(xs.head(), head+n, with, head, thrust::(functor)<VALUE_TYPE>());
}
"""


def _parallel_operator(op, functor)
"""
template<typename A>
void operator#{op}=(const parallel<A> &xs, A ys){
  typedef typename thrust::iterator_value<A>::type VALUE_TYPE;
  A head = xs.head(); 
  size_t n = xs.length();
  thrust::transform(head, head+n, ys, head, thrust::#{functor}<VALUE_TYPE>());
}
"""
end


def all()
op = ['+', '-', '*', '/', '%', '&', '|', '^'] 
functors = ["plus", "minus", "multiplies", "divides", "modulus", "bit_and", "bit_or", "bit_xor"]
s = op.zip(functors).map do |op, functor|
  _parallel_operator(op, functor)
end.join("")
"""
#pragma once
#include <thrusting/parallel.h>
#include <thrust/iterator/iterator_traits.h>
namespace thrusting {
#{s}
}
"""
end

if __FILE__ ==$0
  print all()
end  
