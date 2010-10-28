# rbbase/[names].rb -> [names].h

def gen_header_task(names, rbbase)
  for name in names
    file "#{name}.h" => "#{rbbase}/#{name}.rb" do |t|
      rb = t.prerequisites[0]
      h = t.name
      sh "ruby #{rb} > #{h}"
    end
  end 
  generated_h = names.map { |x| x + ".h" }
  CLOBBER.include(generated_h)
  task :gen_header => generated_h
end
