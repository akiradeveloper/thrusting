#pragma once

namespace thrusting {
#ifndef THRUSTING_USE_DOUBLE_FOR_REAL
  typedef float real;
#else
  typedef double real;
#endif
}

#include "make_real_n.h"
#include "real_n_typedef.h"
