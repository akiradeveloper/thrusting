#pragma once

#include <thrust/iterator/iterator_traits.h>
#include <thrust/device_vector.h>

template<typename Iterator>
typename thrust::iterator_value<Iterator>::type iterator_value_of(Iterator it){
  return *(it);
}

int main(void){
  int _xs[] = {1,2}; thrust::device_vector<int> xs(_xs, _xs+2);
  int _ys[] = {3,4}; thrust::device_vector<int> ys(_ys, _ys+2);
  
  iterator_value_of(make_zip_iterator(make_tuple(xs.begin(), ys.begin())));
  return 0;
}
