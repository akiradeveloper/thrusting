"""
typedef typename tupleN<real>::type realN
"""

def realN(n)
"""
typedef typename tuple#{n}<real>::type real#{n};
"""
end

def all()
"""
#pragma once
namespace thrusting {
#{(2..9).map { |i| realN(i) }.join}
}
"""
end

if __FILE__ == $0
  print all()
end
