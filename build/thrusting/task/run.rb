require "thrusting/build"

def make_xs(as, bs)
  xs = Array.new
  as.each do |a|
    bs.each do |b|
      xs << (a*b)
    end
  end
  xs.sort
end

def get_data_dir
  "#{dir}/data/#{get_machine_name()}/#{dev}"
end

def make_data_dir(dir)
  get_runnable_devices().each do |dev|
    FileUtils.mkdir_p(get_data_dir())
  end
end

def make_run_task_0(dir)
  make_data_dir(dir)
  namespace :run do
    task dir do
      get_runnable_devices().each do |dev|
        f = "#{get_data_dir()}/.dat"
        cmd = "#{dir}/main_on_#{dev}.bin #{f}"
        sh cmd
      end
    end
  end 
end

def make_run_task_1(xs, dir)
  namespace :run do
    task dir => get_runnable_devices().map { |dev| "#{dir}/main_on_#{dev}.bin" } do
      make_data_dir(dir)
      xs.each do |x|
        get_runnable_devices().each do |dev|   
          f = "#{get_data_dir()}/#{x}.dat"
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
    task dir => get_runnable_devices().map { |dev| "#{dir}/main_on_#{dev}.bin" } do
      make_data_dir(dir)
      xs.each do |x|
        ys.each do |y|
          get_runnable_devices().each do |dev|
            f = "#{get_data_dir()}/#{x}_#{y}.dat"
            cmd = "#{dir}/main_on_#{dev}.bin #{f} #{x} #{y}"
            sh cmd
          end
        end
      end
    end
    task :all => dir
  end
end
