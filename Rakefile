require "rake/clean"

thisdir = File.expand_path File.dirname __FILE__ 

CLOBBER.include("doc/html", "doc/latex")

desc "generate API doc under doc dir"
task :doxygen do
  sh "doxygen Doxyfile"
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
