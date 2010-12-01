#include <thrusting/vector.h>
#include <thrusting/algorithm/gather.h>
#include <thrusting/time.h>
#include <thrusting/list.h>

#include <thrust/sequence.h>
#include <thrust/reverse.h>

namespace {
  using namespace thrusting;
}

int main(void){
  size_t N = 10000000;

  vector<int>::type value(N);
  thrust::sequence(value.begin(), value.end());

  vector<int>::type idx(N);
  thrust::sequence(idx.begin(), idx.end());
  thrust::reverse(idx.begin(), idx.end());
  
  thrusting::stopwatch sw("thrusting scatter"); 

  for(int i=0; i<10; ++i){
    sw.begin();
    thrusting::gather(
      idx.begin(),
      idx.end(),
      value.begin(),
      value.begin()); // in-place
    sw.end();
  }
   
  sw.show();

  thrusting::stopwatch sw2("thrust::scatter");     
  vector<int>::type output(N);     
  
  for(int i=0; i<10; ++i){
    sw2.begin();
    thrust::gather(
      idx.begin(),
      idx.end(),
      value.begin(),
      output.begin());
    sw2.end();
  }
  
  sw2.show();
  
  std::cout << make_list(10, output.begin()) << std::endl;
  
  return 0;
}
