#pragma once

/*
  You can switch the hidden type of "real" to type double
  only by adding "-D THRUSTING_USING_DOUBLE_FOR_REAL",
  otherwise "real" means float.
  This is very effective to build a portable software.
*/
#include "real/detail/real_typedef.h"
#include "real/detail/tuple/real.h"
