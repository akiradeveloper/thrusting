#include <thrusting/thrusting.h>
#include <string>
#include <iostream>

template <typename A>
A func(A x, A y) { return x + y; }

int main(void){
  func(10,20);
  return 0;
}
