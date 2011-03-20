#pragma once

#include <thrust/device_vector.h>
#include <thrust/iterator/zip_iterator.h>
#include <thrust/tuple.h>

using namespace thrust; 

int main(void){
  int _xs[] = {1,2}; device_vector<int> xs(_xs, _xs+2);
  int _ys[] = {3,4}; device_vector<int> ys(_ys, _ys+2);
  
  *(make_zip_iterator(make_tuple(xs.begin(), ys.begin()))) = make_tuple(5,6);
      
  return 0;
}
