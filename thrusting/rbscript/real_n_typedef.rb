thisdir = File.expand_path(File.dirname(__FILE__))
require [thisdir, "def_macro"].join "/"

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
#{(TUPLE_MIN..TUPLE_MAX).map { |i| realN(i) }.join}
}
"""
end

if __FILE__ == $0
  print all()
end
