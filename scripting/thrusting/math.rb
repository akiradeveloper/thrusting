module Thrusting
  class << self
  end

  private
  FUNCTIONS = [
    "sin", 
    "cos",
    "tan"]

  def make_function(func)
    txt = 
    """
__device__ __host___
real #{func}(real x){
#ifdef THRUSTING_USING_DOUBLE_FOR_REAL
  return sin(x)
#else
  return sinf(x)
#endif
}
    """
  end
end

if __FILE__ == $0
  include Thrusting
  print make_function("sin")
end
