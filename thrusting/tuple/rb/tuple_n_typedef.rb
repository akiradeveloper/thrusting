thisdir = File.expand_path File.dirname __FILE__ 

require ["thrusting/rb", "get_tuple"].join "/"

"""
template<typename T>
struct tupleN {
  typedef thrust::tuple<T, T, ...> type;
};
"""

def tupleN(n)
arg = (0...n).map { "T" }
"""
template<typename T>
struct tuple#{n} {
  typedef thrust::tuple<#{arg.join(", ")}> type;
};
"""
end

def all()
"""
#pragma once
#include <thrust/tuple.h>
namespace thrusting {
#{(TUPLE_MIN..TUPLE_MAX).map { |i| tupleN(i) }.join}
}
"""
end

if __FILE__ == $0
  print all()
end
