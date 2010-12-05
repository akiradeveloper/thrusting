#include <thrusting/algorithm/reduce_by_bucket.h>
#include <thrusting/vector.h>
#include <thrusting/time.h>
#include <thrusting/list.h>
#include <thrusting/random/generate.h>
#include <thrusting/functional.h>

#include <thrust/iterator/constant_iterator.h>
#include <thrust/sequence.h>
#include <thrust/sort.h>

#include <cstdlib>

#include <algorithm>

namespace {
  using namespace thrusting;
}

int main(int nargs, char **args){
  size_t N_VALUE = atoi(args[1]);
  size_t N_BUCKET = atoi(args[2]);
  std::cout << N_VALUE << std::endl;
  std::cout << N_BUCKET << std::endl;

  thrust::host_vector<int> _value(N_VALUE);
  thrust::sequence(_value.begin(), _value.end());

  vector<int>::type prefix_output(N_BUCKET); 
  vector<int>::type cnt_output(N_BUCKET);
  vector<int>::type value_output(N_BUCKET);

  thrusting::stopwatch sw("reduce_by_bucket"); 

  for(int i=0; i<3; ++i){
    std::random_shuffle(_value.begin(), _value.end());
    vector<int>::type value(_value.begin(), _value.end());

    /*
      create random idx number that is sorted.
    */
    vector<int>::type idx(N_VALUE);
    int lucky_seed = 777;
    thrusting::generate(
      idx.begin(), idx.end(),
      compose(
        make_uniform_int_distribution<int>(0, N_BUCKET),
        make_rng_generator(lucky_seed)));   
    thrust::sort(idx.begin(), idx.end());
//    std::cout << "sorted idx" << std::endl;
//    std::cout << make_list(idx) << std::endl;

    sw.begin();
    thrusting::reduce_by_bucket(
      N_VALUE,
      idx.begin(),
      value.begin(),
      N_BUCKET,
      prefix_output.begin(),
      cnt_output.begin(),
      value_output.begin(),
      777); // NULL VALUE
    sw.end();
  }
  
  sw.show();
  
//  std::cout << make_list(prefix_output) << std::endl;
//  std::cout << make_list(cnt_output) << std::endl;
//  std::cout << make_list(value_output) << std::endl;
  
  return 0;
}
