module Thrusting 

def use_thrust(cc)
  thrust_home = get_THRUST_home() 
  thrust_include = thrust_home
  cc += " -I #{thrust_include}"
end

end # END Thrusting
