if __FILE__ == $0
  s = `cat /proc/cpuinfo`
  #p s
  p s.split("\n").find { |x| x.include? "cpu cores" }.split(":")[1].to_i
end
