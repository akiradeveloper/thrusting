#pragma once

#include <iostream>

__device__ __constant__ int x = 2;

int main(void){

  int y = x+1;
  std::cout << y << std::endl; 

  return 0;
}
