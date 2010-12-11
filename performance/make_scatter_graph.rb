require "gnuplot"

require "thrusting/performance/make_performance_task"

NS = make_xs([1,2,5], [10000,100000]).sort

Gnuplot.open do |gp|
  Gnuplot::Plot.new(gp) do |plot|
    plot.title("comparing gather")
    plot.xlabel "n"
    plot.ylabel "time [ms]"
    plot.terminal("jpeg")
    plot.output("figure/gather_comparison.jpeg")

    
    ["thrusting_gather", "thrust_gather"].each do |dir|
      ["host", "device"].each do |dev|
        ys = []
        NS.each do |n|
          f = File.read("#{dir}/data/#{dev}/#{n}.dat")
          time = f.strip.to_f     
          ys << time
        end 
        plot.data << Gnuplot::DataSet.new( [NS, ys] ) do |ds|
          ds.title = "#{dir} on #{dev}"
          ds.with = "lines"
        end
      end
    end
  end
end
