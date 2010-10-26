#include <thrust/device_vector.h>
#include <thrust/equal.h>
#include <cassert>

int main(void){
  int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 
  int xs2[] = {1,2}; thrust::device_vector<int> d_xs2(xs2, xs2+2); 
  bool are_equal = thrust::equal(d_xs.begin(), d_xs.end(), d_xs2.begin());
  return 0;
}
