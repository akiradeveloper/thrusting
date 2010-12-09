def use_thrust(cc)
  thrust_home = "#{ENV["HOME"]}/local/thrust"
  thrust_include = thrust_home
  cc += " -I #{thrust_include}"
end
