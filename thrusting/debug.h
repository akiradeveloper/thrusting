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

#ifndef THRUSTING_ASSERTION_UNABLED
  #ifndef THRUSTING_DEBUG
    #define THRUSTING_DEBUG 
  #endif
#endif

#define THRUSTING_CHECK(BOOL) thrusting::check((BOOL))

#include <cassert>

namespace thrusting {

/*
  temporarily using assert but,
  this should be able to be used in device code
*/
void check(bool b){
#ifdef THRUSTING_DEBUG
  assert(b);
#endif
}

}
  
