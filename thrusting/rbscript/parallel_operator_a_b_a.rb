thisdir = File.expand_path(File.dirname(__FILE__))
require [thisdir, "def_macro"].join "/"

def all()
"""
#pragma once
namespace thrusting {
}
"""
end

if __FILE__ == $0
  print all()
end
