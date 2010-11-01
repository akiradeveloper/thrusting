thisdir = File.expand_path File.dirname __FILE__  

require ["thrusting/rb", "tuple_min_max"].join "/"

def realN(n)
"""
typedef typename tuple#{n}<real>::type real#{n};
"""
end

def all()
"""
#pragma once
#include <thrusting/tuple.h>
namespace thrusting {
#{(TUPLE_MIN..TUPLE_MAX).map { |i| realN(i) }.join}
}
"""
end

if __FILE__ == $0
  $stdout << all()
end
