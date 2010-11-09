#pragma once

#include <thrust/tuple.h>

#include "tuple/detail/make_string/make_string.h"
#include "tuple/detail/n_typedef/n_typedef.h"

/*
  Akira Hayakawa 2010 11/9
  operator overloading
  client uses these functionality only by 

  using namespace thrusting::op
*/
#include "op/tuple/detail/equality.h"
#include "op/tuple/detail/n_operator.h"
#include "op/tuple/detail/operator.h"
#include "op/tuple/detail/ostream.h"
