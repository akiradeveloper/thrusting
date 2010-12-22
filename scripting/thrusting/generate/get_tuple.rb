["tuple_min_max"].each do |f|
  require "thrusting/generate/#{f}"
end

# Macro to hide how to get item from value

module Thrusting
module Detail

  module_function
  def get_tuple(i, tuple)
  """
  thrust::get<#{i}>(#{tuple})
  """
  end

end
end

if __FILE__ == $0
  print get_tuple(1, "x")
end
