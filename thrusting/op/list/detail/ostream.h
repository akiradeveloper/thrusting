#pragma once

#include <iostream>

namespace thrusting {

template<typename Iterator>
std::ostream &operator<<(std::ostream &os, const thrusting::list<Iterator> &xs){
  return os << thrusting::make_string(xs);
}

} // END thrusting
