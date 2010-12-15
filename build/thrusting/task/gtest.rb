module Thrusting

  module_function
  def make_gtest_task(cc, mode, dir)
    hs = FileList["#{dir}/*.h"].exclude("#{dir}/all.h")
    file "#{dir}/all.h" => hs do |t|
      f = File.open(t.name, "w")
      f.write("#pragma once\n")
      txt = hs.map { |h| "#include \"#{File.basename(h)}\"" }.join "\n"
      f.write(txt)
      f.close
    end
    CLOBBER.include("#{dir}/all.h")
  
    cc = use_gtest(cc)
    p cc
    make_compile_task(cc, mode, dir)
  
    outputdir = "#{dir}/regression/#{get_machine_name()}"
    FileUtils.mkdir_p(outputdir)

    namespace :regress do
      get_runnable_devices().each do |dev|
        task "on_#{dev}" => ["#{dir}/all.h", "#{dir}/all_on_#{dev}.bin"] do |t|
          system "#{dir}/all_on_#{dev}.bin 1> #{outputdir}/#{dev}"
        end
        task :on_all => "on_#{dev}" 
      end
    end
  end
end 
