#pragma once

#include <thrusting/real.h>

namespace thrusting {

real sinr(real rad){
#ifdef THRUSTING_USING_DOUBLE_FOR_REAL
  return sin(rad);
#else
  return sinf(rad);
#endif
}

real cosr(real rad){
#ifdef THRUSTING_USING_DOUBLE_FOR_REAL
  return cos(rad);
#else
  return conf(rad);
#endif
}

real sqrtr(real x){
#ifdef THRUSTING_USING_DOUBlE_FOR_REAL
  return sqrt(x);
#else
  return sqrtf(x);
#endif
}

} // END thrusting
