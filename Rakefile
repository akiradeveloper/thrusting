thisdir = File.expand_path File.dirname __FILE__ 

require "rake/clean"

["version"].each do |f|
  require "thrusting/detail/#{f}"
end

CLOBBER.include ["doc/html", "doc/latex"]

desc "generate zip file"
task :zip do
  sh "hg archive -t zip #{ENV["HOME"]}/thrusting-v#{VERSION}.zip"
end

desc "generate API doc under doc dir"
task :doxygen do
  sh "doxygen Doxyfile"
end

task :push => [:remove_deprecated] do
  repo = "http://bitbucket.org/akiradeveloper/thrusting"
  sh "hg push #{repo}"
end

task :remove_deprecated do 
  p $:
  `hg status`.split("\n").grep(/^!/).each do |x|
    sh "hg remove #{x.split.at(1)}"
  end
end

task :clobber do
  ["testing", "performance"].each do |dir|
    Dir.chdir(dir) do
      sh "rake clobber"
    end
  end
end
