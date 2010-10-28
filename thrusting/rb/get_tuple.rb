thisdir = File.expand_path File.dirname __FILE__ 
require ["thrusting/rb", "tuple_min_max"].join "/"

# Macro to hide how to get item from value

def get_tuple(i, tuple)
"""
thrust::get<#{i}>(#{tuple})
"""
end

if __FILE__ == $0
  print get_tuple(1, "x")
end
