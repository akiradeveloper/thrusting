#pragma once

#include <iostream>

namespace thrusting {
namespace op {
namespace list {

template<typename Iterator>
std::ostream &operator<<(std::ostream &os, const thrusting::detail::list<Iterator> &xs){
  return os << thrusting::make_string(xs);
}

}
}
}
