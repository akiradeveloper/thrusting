#pragma once


#include <thrust/host_vector.h>

int main(void){
  thrust::host_vector<float> vec(0);
  vec.push_back(10.0F);
  return 0;
}
