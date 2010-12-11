def make_build_task(dirs)
  dirs.each do |dir|
    task :build do
      Dir.chdir(dir) do
        sh "rake build"
      end
    end
  end
end

def make_clobber_task(dirs)
  dirs.each do |dir|
    task :build do
      Dir.chdir(dir) do
        sh "rake clobber"
      end
    end
  end
end

def make_autogen_task(dirs)
  make_build_task(dirs)
  make_clobber_task(dirs)
end
