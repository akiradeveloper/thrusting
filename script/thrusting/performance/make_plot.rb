thisdir = File.expand_path File.dirname __FILE__
require "#{thisdir}/device"
require "gnuplot"

def make_xs_plot(plot, xs, dir)
  PERFORMANCE_DEVICES.each do |dev|
    ys = []
    xs.each do |x|
      f = File.read("#{dir}/data/#{dev}/#{x}.dat")
      time = f.strip.to_f     
      ys << time
    end 
    plot.data << Gnuplot::DataSet.new( [xs, ys] ) do |ds|
      ds.title = "#{dir} on #{dev}"
      ds.with = "lines"
    end
  end
end

def make_xs_ys_plot(plot, xs, ys, dir)
  PERFORMANCE_DEVICES.each do |dev|
    zs = []
    xs.each_with_index do |x, i|
      zs[i] = []
      ys.each_with_index do |y, j|
        f = File.read("reduce_by_bucket/data/#{dev}/#{x}_#{y}.dat")
        time = f.strip.to_f
        zs[i][j] = time
      end
    end
    plot.data << Gnuplot::DataSet.new( [xs, ys, zs] ) do |ds|
      ds.title = "#{dir} on #{dev}"
      # ds.with = "lines"
    end  
  end
end

def make_xs_y_plot(plot, xs, y, dir)
  PERFORMANCE_DEVICES.each do |dev|
    zs = []
    xs.each do |x|
      f = File.read("reduce_by_bucket/data/#{dev}/#{x}_#{y}.dat")
      time = f.strip.to_f     
      zs << time
    end 
    plot.data << Gnuplot::DataSet.new( [xs, zs] ) do |ds|
      ds.title = "#{dir} on #{dev}"
      ds.with = "lines"
    end
  end
end

def make_x_ys_plot(plot, x, ys, dir)
  PERFORMANCE_DEVICES.each do |dev|
    zs = []
    ys.each do |y|
      f = File.read("reduce_by_bucket/data/#{dev}/#{x}_#{y}.dat")
      time = f.strip.to_f     
      zs << time
    end 
    plot.data << Gnuplot::DataSet.new( [ys, zs] ) do |ds|
      ds.title = "#{dir} on #{dev}"
      ds.with = "lines"
    end
  end
end
