#include <thrusting/vector.h>
#include <thrusting/algorithm/gather.h>
#include <thrusting/time.h>
#include <thrusting/list.h>

#include <thrust/sequence.h>

#include <cstdlib>
#include <algorithm>

namespace {
  using namespace thrusting;
}

int main(int narg, char **args){
  size_t N = atoi(args[1]);

  thrust::host_vector<int> _value(N);
  thrust::sequence(_value.begin(), _value.end());

  thrust::host_vector<int> _idx(N);
  thrust::sequence(_idx.begin(), _idx.end());

  thrusting::stopwatch sw("thrusting"); 

  for(int i=0; i<1; ++i){
    std::random_shuffle(_value.begin(), _value.end());
    vector<int>::type value(_value.begin(), _value.end());

    std::random_shuffle(_idx.begin(), _idx.end());
    vector<int>::type idx(_idx.begin(), _idx.end());

    sw.begin();
    thrusting::gather(
      idx.begin(),
      idx.end(),
      value.begin(),
      value.begin()); // in-place
    sw.end();
  }
   
  sw.show();

  thrusting::stopwatch sw2("thrust");     
  vector<int>::type output(N);     
  
  for(int i=0; i<1; ++i){
    std::random_shuffle(_value.begin(), _value.end());
    vector<int>::type value(_value.begin(), _value.end());

    std::random_shuffle(_idx.begin(), _idx.end());
    vector<int>::type idx(_idx.begin(), _idx.end());

    sw2.begin();
    thrust::gather(
      idx.begin(),
      idx.end(),
      value.begin(),
      output.begin());
    sw2.end();
  }
  
  sw2.show();
  
  return 0;
}
