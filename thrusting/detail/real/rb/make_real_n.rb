thisdir = File.expand_path File.dirname __FILE__  

["tuple_min_max", "template_type"].each do |s|
  require "thrusting/rb/#{s}"
end

def make_realN(n)
"""
__host__ __device__
real#{n} make_real#{n}(#{explicit_type_arg("real", 0...n)}){
  return make_tuple#{n}<real>(#{arg(0...n)});
}
"""
end  
  
def all()
"""
#pragma once
#include <thrusting/real.h>
#include <thrusting/tuple.h>
namespace thrusting {
#{(TUPLE_MIN..TUPLE_MAX).map { |i| make_realN(i) }.join("") }
}
"""
end

if __FILE__ == $0
  $stdout << all()
end
  
