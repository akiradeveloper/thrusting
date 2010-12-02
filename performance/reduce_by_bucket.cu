#include <thrusting/algorithm/reduce_by_bucket.h>
#include <thrusting/vector.h>
#include <thrusting/time.h>
#include <thrusting/list.h>

#include <thrust/iterator/constant_iterator.h>
#include <thrust/sequence.h>
#include <thrust/sort.h>

#include <stdlib.h>

#include <algorithm>

namespace {
  using namespace thrusting;
}

namespace thrusting {
struct random {
  random(int seed)
  {
    srand(seed);
  }
  int operator()(int ceil) const {
    float r = rand();
    float n = ceil * (r-1) / RAND_MAX;
    return (int) n;
  }  
};
} // END thrusting

int main(void){
  size_t N_VALUE = 10000000;
  size_t N_BUCKET = 500000;

  vector<int>::type prefix_output(N_BUCKET); 
  vector<int>::type cnt_output(N_BUCKET);
  vector<int>::type value_output(N_BUCKET);

  thrusting::stopwatch sw("reduce_by_bucket"); 

  for(int i=0; i<3; ++i){
    thrust::host_vector<int> _value(N_VALUE);
    thrust::sequence(_value.begin(), _value.end());
    std::random_shuffle(_value.begin(), _value.end());
    vector<int>::type value(_value.begin(), _value.end());

    thrust::host_vector<int> _idx(N_VALUE);
    int lucky_seed = 777;
    thrusting::random ran(lucky_seed);
    thrust::transform(
      thrust::make_constant_iterator(N_BUCKET),
      thrust::make_constant_iterator(N_BUCKET) + N_VALUE,
      _idx.begin(),
      ran); 
    vector<int>::type idx(_idx.begin(), _idx.end());
    thrust::sort(idx.begin(), idx.end());

    cudaThreadSynchronize();
    sw.begin();

    thrusting::reduce_by_bucket(
      N_VALUE,
      value.begin(),
      idx.begin(),
      N_BUCKET,
      prefix_output.begin(),
      cnt_output.begin(),
      value_output.begin(),
      777); // NULL VALUE
    
    cudaThreadSynchronize();
    sw.end();
  }
  
  sw.show();
  
  return 0;
}
