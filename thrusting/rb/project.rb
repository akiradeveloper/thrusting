thisdir = File.expand_path File.dirname __FILE__

["version.rb", "developer.rb"].each do |f|
   require "#{thisdir}/f"
end
