def get_tuple(i, tuple)
"""
thrust::get<#{i}>(#{tuple})
"""
end

TUPLE_MIN = 2
TUPLE_MAX = 9

if __FILE__ == $0
  print get_tuple(1, "x")
end
