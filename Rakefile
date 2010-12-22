thisdir = File.expand_path File.dirname __FILE__ 

require "rake/clean"

CLOBBER.include ["doc/html", "doc/latex"]

namespace :download do
  task :thrust do
  end
  task :gnuplotrb do
  end
  task :all do
  end
end

task :build do
  Dir.chdir("bin") do
    sh "rake build"
  end
end

task :clobber do
  p "CLOBBBERREEEEEE"
  Dir.chdir("bin") do
    p ENV["PWD"]
    sh "rake clobber"
  end
end

desc "generate zip file"
task :zip do
  version = "0.0.1"
  sh "hg archive -t zip #{ENV["HOME"]}/thrusting-v#{version}.zip"
end

desc "generate API doc under doc dir"
task :doxygen do
  sh "doxygen Doxyfile"
end

task :add => [:clobber, :remove_deprecated] do
  sh "hg add"
end

task :push do
  repo = "http://bitbucket.org/akiradeveloper/thrusting"
  sh "hg push #{repo}"
end

task :remove_deprecated do 
  p $:
  `hg status`.split("\n").grep(/^!/).each do |x|
    sh "hg remove #{x.split.at(1)}"
  end
end
