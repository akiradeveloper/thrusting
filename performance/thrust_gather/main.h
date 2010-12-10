#pragma once

#include <thrusting/vector.h>
#include <thrusting/algorithm/gather.h>
#include <thrusting/time.h>
#include <thrusting/list.h>

#include <thrust/sequence.h>

#include <cstdlib>
#include <algorithm>
#include <fstream>

namespace {
  using namespace thrusting;
}

int main(int narg, char **args){
  char *filename = args[1];
  size_t N = atoi(args[2]);

  thrust::host_vector<int> _value(N);
  thrust::sequence(_value.begin(), _value.end());

  thrust::host_vector<int> _idx(N);
  thrust::sequence(_idx.begin(), _idx.end());

  thrusting::stopwatch sw("thrust");     
  vector<int>::type output(N);     
  
  for(int i=0; i<1; ++i){
    std::random_shuffle(_value.begin(), _value.end());
    vector<int>::type value(_value.begin(), _value.end());

    std::random_shuffle(_idx.begin(), _idx.end());
    vector<int>::type idx(_idx.begin(), _idx.end());

    sw.begin();
    thrust::gather(
      idx.begin(),
      idx.end(),
      value.begin(),
      output.begin());
    sw.end();
  }
  
  sw.show();

  std::ofstream ofs(filename);
  ofs << sw.average() << std::endl;
  
  return 0;
}
