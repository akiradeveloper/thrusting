#pragma once

#include "list/detail/def_list.h"
#include "list/detail/make_list.h"
#include "list/detail/make_string.h"

#include "op/list/detail/ostream.h"

/*
  Akira Hayakawa, 2010 11/8
  It is usually not a good idea to write using directive in header file.
  This in an exception.
  In my environment, mac 10.6, the compiler does not detect operator overloading for list class
  without declare using the op namespace.
  namespace thrusting::op::list should not be used by client.
*/
// using namespace thrusting::op::list;
