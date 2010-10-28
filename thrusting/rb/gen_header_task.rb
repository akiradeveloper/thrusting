require "rake/clean"

def gen_header_name(rbfile, base)
  base = File.expand_path base
  h_name = File.basename(rbfile, ".rb") + ".h"
  return [base, h_name].join "/"
end

def gen_header_task(rbfiles, base=".")
  for rbfile in rbfiles
    rbfile = File.expand_path rbfile
    file gen_header_name(rbfile, base) => rbfile do |t|
      rb = t.prerequisites[0]
      h = t.name
      sh "ruby #{rb} > #{h}"
    end
  end 
  generated_h = rbfiles.map { |rbfile| gen_header_name(rbfile, base) }
  CLOBBER.include(generated_h)
  task :gen_header => generated_h
end

if __FILE__ == $0
  p gen_header_name("aaa.rb", ".")
end
