#include <thrusting/vector.h>
#include <thrusting/algorithm/scatter.h>
#include <thrusting/real.h>
#include <thrusting/time.h>

#include <thrust/sequence.h>
#include <thrust/reverse.h>

namespace {
  using namespace thrusting;
}

int main(void){
  size_t N = 1000000;

  vector<int>::type value(N);
  thrust::sequence(value.begin(), value.end());

  vector<int>::type idx(N);
  thrust::sequence(idx.begin(), idx.end());
  thrust::reverse(idx.begin(), idx.end());
  
  thrusting::stopwatch sw("thrusting scatter"); 

  for(int i=0; i<10; ++i){
    sw.begin();
    thrusting::scatter(
      value.begin(),
      value.end(),
      idx.begin(),
      value.begin()); // in-place
    sw.end();
  }
   
  sw.show();

  thrusting::stopwatch sw2("thrust::scatter");     
  vector<int>::type output(N);     
  
  for(int i=0; i<10; ++i){
    sw2.begin();
    thrust::scatter(
      value.begin(),
      value.end(),
      idx.begin(),
      output.begin());
    sw2.end();
  }
  
  sw2.show();
  
  return 0;
}
