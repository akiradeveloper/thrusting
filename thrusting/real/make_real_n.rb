thisdir = File.expand_path(File.dirname(__FILE__))
require [thisdir, "..", "tuple_min_max"].join "/"

"""
realN make_realN(real x1, real x2, ...){
  return make_tupleN<real>(x1, x2, ...);
}
"""

def make_realN(n)
arg = (0...n).map { |i| "real x#{i}" }
input = (0...n).map { |i| "x#{i}" }
"""
__host__ __device__
real#{n} make_real#{n}(#{arg.join(", ")}){
  return make_tuple#{n}<real>(#{input.join(", ")});
}
"""
end  
  
def all()
"""
#pragma once
#include \"real_n_typedef.h\"
#include <thrusting/tuple/make_tuple_n.h>
namespace thrusting {
#{(TUPLE_MIN..TUPLE_MAX).map { |i| make_realN(i) }.join("") }
}
"""
end

if __FILE__ == $0
  print all()
end
  
