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
#include <thrust/tuple.h>
#pragma once
namespace thrusting {
#{(2..9).map { |i| tupleN(i) }.join}
}
"""
end

if __FILE__ == $0
  print all()
end
