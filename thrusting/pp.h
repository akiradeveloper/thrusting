#pragma once

#include <iostream>
#include <string>

#define THRUSTING_PP(OBJ) thrusitng::pp((OBJ), __FILE__, __LINE__)

namespace thrusting {

template<
typename Object>
void pp(Object obj, std::string filename, size_t lineno){
#ifndef THRUSTING_PRITTY_PRINT_UNABLED
 std::cout << "FILENAME: " << filename << " " << "L" << lineno << std::endl;
  std::cout << obj << std::endl;
#endif
}

} // END thrusting

