require ["thrusting/rb", "tuple_min_max"].join "/"

"""
template<typename X0>
thrust::zip_iterator<thrust::tuple<X0>> make_zip_iterator(X0 x0){
  return thrust::make_zip_iterator(thrust::make_tuple(x0));
}
"""

def make_zip_iterator(n)
template_param = (0...n).map { |i| "typename X#{i}" }.join ", "
tuple_param = (0...n).map { |i| "X#{i}" }.join ", "
arg = (0...n).map { |i| "X#{i} x#{i}" }.join ", "
tuple_arg = (0...n).map { |i| "x#{i}" }.join ", "
"""
template<#{template_param}>
thrust::zip_iterator<thrust::tuple<#{tuple_param}>> make_zip_iterator(#{arg}){
  return thrust::make_zip_iterator(thrust::make_tuple(#{tuple_arg}));
}
"""
end

def all()
code = (TUPLE_MIN..TUPLE_MAX).map { |i| make_zip_iterator(i) }.join "\n"
"""
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
