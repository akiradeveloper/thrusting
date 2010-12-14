def make_compile_task(cc, dir)
  files = FileList["#{dir}/*.h"]
  files.each do |f|
    name = File.basename(f, ".h")
    get_runnable_devices().each do |backend|
      binname = "#{name}_on_#{type}.bin"
      file "#{dir}/#{binname}" => f do |t|
        cuname = "#{name}.cu"
        tmp = File.open("#{dir}/#{cuname}", "w")
        txt =
        """
        #include \"#{name}.h\"
        """
        tmp.write(txt)
        tmp.close
        _cc = use_device(cc, backend)
        p _cc 
        sh "#{_cc} -o #{dir}/#{binname} #{dir}/#{cuname}"
        FileUtils.rm("#{dir}/#{cuname}")
      end
      namespace :compile do
        task dir => "#{dir}/#{binname}"
        task :all => dir
      end
      namespace :clobber do
        task dir do
          sh "rm -rf #{dir}/#{binname}"
        end
      end
      CLOBBER.include("#{dir}/#{binname}")
    end
  end
end
