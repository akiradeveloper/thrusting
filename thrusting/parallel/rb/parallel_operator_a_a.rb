thisdir = File.expand_path File.dirname __FILE__ 

require "thrusting/rb/namespace"

def all()
"""
#pragma once
#{operator_parallel("")}
"""
end

if __FILE__ == $0
  print all()
end
