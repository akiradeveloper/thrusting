def make_build_clobber_task(dir)
  namespace dir do
    file = "#{dir}/Rakefile"
    task :build =>  file do
      Dir.chdir(dir) do
        sh "rake build"
      end 
    end
    task :clobber => file do
      Dir.chdir(dir) do
        sh "rake clobber"
      end
    end
  end
end

def make_build_task(dirs)
  task :build => dirs.map { |dir| dir + ":build" }
end

def make_clobber_task(dirs)
  task :clobber => dirs.map { |dir| dir + ":clobber" }
end

def make_autogen_task(dirs)
  dirs.each do |dir|
    make_build_clobber_task(dir)
  end
  make_build_task(dirs)
  make_clobber_task(dirs)
end
