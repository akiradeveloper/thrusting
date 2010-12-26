thisdir = File.expand_path File.dirname __FILE__
require "#{thisdir}/system"

module Thrusting
  def nvcc_config(cxx)
    homepath = get_cuda_home
    libpath = [homepath, "lib"].join "/"
    # if on 64 bit, use lib64 instead
    if get_machine_bit == 64
      libpath += "64"
    end
    cxx += " -L #{libpath}"

    incpath = [homepath, "include"].join "/"
    cxx += " -I #{incpath}"
    return cxx
  end
class << self
  private
  def guess_cuda_home
    compiler_path = `which nvcc`.rstrip.split(File::SEPARATOR)
    idx = compiler_path.index("cuda") + 1
    return compiler_path.slice(0, idx).join File::SEPARATOR
  end
  def get_cuda_home
    return guess_cuda_home
  end
end
end

if __FILE__ == $0
  include Thrusting
  nvcc_config("nvcc")
end
