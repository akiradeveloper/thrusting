thisdir = File.expand_path File.dirname(__FILE__)

task :setup do
  $: << thisdir
  p $:
end

task :push do
  repo = "http://bitbucket.org/akiradeveloper/thrusting"
  sh "hg push #{repo}"
end

task :purge_ => [:setup] do 
  `hg status`.split("\n").grep(/^!/).each do |x|
    sh "hg remove #{x.split.at(1)}"
  end
end
