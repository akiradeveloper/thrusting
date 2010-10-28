thisdir = File.expand_path File.dirname __FILE__  

require ["thrusting/rb", "tuple_min_max"].join "/"

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
#include \"real_typedef.h\"
#include <thrusting/tuple/tuple_n_typedef.h>
namespace thrusting {
#{(TUPLE_MIN..TUPLE_MAX).map { |i| realN(i) }.join}
}
"""
end

if __FILE__ == $0
  print all()
end
