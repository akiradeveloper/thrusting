if __FILE__ == $0
  s = `/usr/sbin/system_profiler`
  p s.split("\n").select { |x| x.include?("Total Number Of Cores") }[0].split(":")[1].to_i
end
