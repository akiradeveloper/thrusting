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

def make_data_dir(dir)
  PERFORMANCE_DEVICES.each do |dev|
    FileUtils.mkdir_p("#{dir}/data/#{dev}")
  end
end

def make_run_task_0(dir)
  make_data_dir(dir)
  namespace :run do
    task dir do
      PERFORMANCE_DEVICES.each do |dev|
        f = "#{dir}/data/#{dev}/.dat"
        cmd = "#{dir}/main_on_#{dev}.bin #{f}"
        sh cmd
      end
    end
  end 
end

def make_run_task_1(xs, dir)
  namespace :run do
    task dir => PERFORMANCE_DEVICES.map { |dev| "#{dir}/main_on_#{dev}.bin" } do
      make_data_dir(dir)
      xs.each do |x|
        PERFORMANCE_DEVICES.each do |dev|   
          f = "#{dir}/data/#{dev}/#{x}.dat"
          cmd = "#{dir}/main_on_#{dev}.bin #{f} #{x}"
          sh cmd
        end
      end
    end
    task :all => dir
  end
end

def make_run_task_2(xs, ys, dir)
  namespace :run do
    task dir => PERFORMANCE_DEVICES.map { |dev| "#{dir}/main_on_#{dev}.bin" } do
      make_data_dir(dir)
      xs.each do |x|
        ys.each do |y|
          PERFORMANCE_DEVICES.each do |dev|
            f = "#{dir}/data/#{dev}/#{x}_#{y}.dat"
            cmd = "#{dir}/main_on_#{dev}.bin #{f} #{x} #{y}"
            sh cmd
          end
        end
      end
    end
    task :all => dir
  end
end
