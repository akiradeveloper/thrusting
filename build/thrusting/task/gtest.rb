module Thrusting
  module_function
  def make_gtest_task(cc, dir)
    cc = use_gtest(cc)
    hs = FileList["*.h"]
    file "all.h" => hs do |t|
      f = File.open(t.name, "w")
      f.write("#pragma once\n")
      txt = hs.map { |h| "#include \"#{h}\"" }.join "\n"
      f.write(txt)
      f.close
    end
  
    make_compile_task(cc, dir)
  
    outputdir = "#{dir}/regression/#{get_machine_name()}"
    FileUtils.mkdir(outputdir)
    namespace :regress do
      task :on_host => "#{dir}/all_on_host.bin" do |t|
        system "#{dir}/all_on_host.bin 1> #{outputdir}/host"
      end
      
      task :on_device => "#{dir}/all_on_device.bin" do |t|
        system "#{dir}/all_on_device.bin 1> #{outputdir}/device"
      end
      
      task :on_omp => "#{dir}/all_on_omp.bin" do |t|
        system "#{dir}/all_on_omp.bin 1> #{outputdir}/omp"
      end
      
      desc("Run all the test on all devices")
      task :on_all => [:on_host, :on_device, :on_omp]
    end
  end
end 
