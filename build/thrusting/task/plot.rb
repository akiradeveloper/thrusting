require "gnuplot"

require "thrusting/build"

module Thrusting
  
  class << self
    private
  end

  module_function
   
  def get_figure_dir(currdir)
    return "#{currdir}/figure/#{get_machine_name()}"
  end
  
  def make_xs_plot(plot, xs, dir)
    get_runnable_devices().each do |dev|
      ys = []
      xs.each do |x|
        f = File.read("#{get_data_dir(dir, dev)}/#{x}.dat")
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
    get_runnable_devices().each do |dev|
      zs = []
      xs.each_with_index do |x, i|
        zs[i] = []
        ys.each_with_index do |y, j|
          f = File.read("#{get_data_dir(dir, dev)}/#{x}_#{y}.dat")
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
    get_runnable_devices().each do |dev|
      zs = []
      xs.each do |x|
        f = File.read("#{get_data_dir(dir, dev)}/#{x}_#{y}.dat")
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
    get_runnable_devices().each do |dev|
      zs = []
      ys.each do |y|
        f = File.read("#{get_data_dir(dir, dev)}/#{x}_#{y}.dat")
        time = f.strip.to_f     
        zs << time
      end 
      plot.data << Gnuplot::DataSet.new( [ys, zs] ) do |ds|
        ds.title = "#{dir} on #{dev}"
        ds.with = "lines"
      end
    end
  end
end
