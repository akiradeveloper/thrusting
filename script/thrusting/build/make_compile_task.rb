require "rake/clean"

["compile_option"].each do |f|
  require "thrusting/build/#{f}"
end

def make_compile_task(cc, dir)
  namespace dir do
    files = FileList["#{dir}/*.h"]
    files.each do |f|
      name = File.basename(f, ".h")
      ["host", "device", "omp"].each do |type|
        binname = "#{name}_on_#{type}"
        task binname => f do |t|
          cuname = "#{name}.cu"
          tmp = File.open("#{dir}/#{cuname}", "w")
          txt =
          """
          #include \"#{name}.h\"
          """
          tmp.write(txt)
          tmp.close
    
          _cc = with_device(cc, type)
          p __FILE__
          p _cc 
          system "#{_cc} -o #{dir}/#{binname} #{dir}/#{cuname}"

          FileUtils.rm("#{dir}/#{cuname}")
        end
        CLOBBER.include("#{dir}/#{binname}")
      end
    end
  end
end
