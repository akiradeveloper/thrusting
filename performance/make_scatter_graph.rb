require "gnuplot"

Gnuplot.open do |gp|
  Gnuplot::Plot.new(gp) do |plot|
    plot.title("comparing scatter")
    plot.size("square 0.5,0.5")
    plot.terminal("png")
    plot.output("figure/hoge.png")
  end
end
