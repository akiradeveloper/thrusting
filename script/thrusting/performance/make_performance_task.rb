thisdir = File.expand_path File.dirname __FILE__
require "#{thisdir}/device"

def make_xs(as, bs)
  xs = Array.new
  as.each do |a|
    bs.each do |b|
      xs << (a*b)
    end
  end
  xs.sort
end

def make_performance_task_1(dir, xs)
  namespace :run do
    task dir => PERFORMANCE_DEVICES.map { |dev| "#{dir}/main_on_#{dev}" } do
      xs.each do |x|
        DEVICES.each do |dev|   
          f = "#{dir}/data/#{dev}/#{x}.dat"
          cmd = "#{dir}/main_on_#{dev} #{f} #{x}"
          sh cmd
        end
      end
    end
    task :all => dir
  end
end

def make_performance_task_2(dir, xs, ys)
  namespace :run do
    task dir => PERFORMANCE_DEVICES.map { |dev| "#{dir}/main_on_#{dev}" } do
      xs.each do |x|
        ys.each do |y|
          PERFORMANCE_DEVICES.each do |dev|
            f = "#{dir}/data/#{dev}/#{x}_#{y}.dat"
            cmd = "#{dir}/main_on_#{dev} #{f} #{x} #{y}"
            sh cmd
          end
        end
      end
    end
    task :all => dir
  end
end
