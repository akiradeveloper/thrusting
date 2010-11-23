#pragma once

#include <iostream>

namespace thrusting {
namespace detail {

template<typename Iterator>
std::ostream &operator<<(std::ostream &os, const thrusting::detail::list<Iterator> &xs){
  return os << thrusting::make_string(xs);
}

} // END detail
} // END detail
