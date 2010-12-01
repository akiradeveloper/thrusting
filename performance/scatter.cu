#include <thrusting/vector.h>
#include <thrusting/algorithm/scatter.h>
#include <thrusting/real.h>
#include <thrusting/time.h>

#include <thrust/sequence.h>
#include <thrust/reverse.h>

#include <algorithm>

namespace {
  using namespace thrusting;
}

int main(void){
  size_t N = 1000000;

  thrust::host_vector<int> _value(N);
  thrust::sequence(_value.begin(), _value.end());

  thrust::host_vector<int> _idx(N);
  thrust::sequence(_idx.begin(), _idx.end());
  
  thrusting::stopwatch sw("thrusting"); 

  for(int i=0; i<3; ++i){
    std::random_shuffle(_value.begin(), _value.end());
    vector<int>::type value(_value.begin(), _value.end());

    std::random_shuffle(_idx.begin(), _idx.end());
    vector<int>::type idx(_idx.begin(), _idx.end());

    sw.begin();
    thrusting::scatter(
      value.begin(),
      value.end(),
      idx.begin(),
      value.begin()); // in-place
    
    sw.end();
  }
   
  sw.show();

  thrusting::stopwatch sw2("thrust");     
  vector<int>::type output(N);     
  
  for(int i=0; i<10; ++i){
    std::random_shuffle(_value.begin(), _value.end());
    vector<int>::type value(_value.begin(), _value.end());

    std::random_shuffle(_idx.begin(), _idx.end());
    vector<int>::type idx(_idx.begin(), _idx.end());

    sw2.begin();
    thrust::scatter(
      value.begin(),
      value.end(),
      idx.begin(),
      output.begin());

    // not needed though
    cudaEvent_t stop;
    cudaEventCreate( &stop );
    cudaEventSynchronize( stop );

    sw2.end();
  }
  
  sw2.show();
  
  return 0;
}
