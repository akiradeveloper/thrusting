# generate namespace from dir
# generate build, clobber tasks
def gen_namespace(dir)
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

def gen_build_task(dirs)
  desc "generate .h files"
  task :build => dirs.map { |dir| dir + ":build" }
end

def gen_clobber_task(dirs)
  task :clobber => dirs.map { |dir| dir + ":clobber" }
end

def gen_autogen_task(dirs)
  dirs.each do |dir|
    gen_namespace(dir)
  end
  gen_build_task(dirs)
  gen_clobber_task(dirs)
end
