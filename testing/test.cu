#include <thrusting/thrusting.h>
#include <string>
#include <iostream>

namespace {
  using namespace thrusting;
}

template <typename A>
A func(A x, A y) { return x + y; }

int main(void){
  thrusting::int3 x;
  func(10,20);
  return 0;
}
