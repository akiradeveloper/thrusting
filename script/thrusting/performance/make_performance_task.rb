def make_xs(as, bs)
  xs = Array.new
  as.each do |a|
    bs.each do |b|
      xs << (a*b)
    end
  end
  xs
end

def make_performance_task_1(dir, xs)
end

def make_performance_task_2(dir, xs, ys)
end
