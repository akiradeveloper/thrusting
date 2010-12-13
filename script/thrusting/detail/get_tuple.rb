["tuple_min_max"].each do |f|
  require "thrusting/detail/#{f}"
end

module Thrusting 

# Macro to hide how to get item from value

def get_tuple(i, tuple)
"""
thrust::get<#{i}>(#{tuple})
"""
end

end # END Thrusting


if __FILE__ == $0
  print get_tuple(1, "x")
end
