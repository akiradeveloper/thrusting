#pragma once

#include <thrusting/vector.h>
#include <thrusting/real.h>
#include <thrusting/time.h>

#include <thrust/scatter.h>
#include <thrust/sequence.h>

#include <cstdio>
#include <cstdlib>
#include <algorithm>

namespace {
  using namespace thrusting;
}

/*
  args
  filename, N
*/
int main(int narg, char **args){
  char *filename = args[1];
  size_t N = atoi(args[2]);

  thrust::host_vector<int> _value(N);
  thrust::sequence(_value.begin(), _value.end());

  thrust::host_vector<int> _idx(N);
  thrust::sequence(_idx.begin(), _idx.end());

  vector<int>::type output(N);     

  thrusting::stopwatch sw("thrust");     
  
  for(int i=0; i<1; ++i){
    std::random_shuffle(_value.begin(), _value.end());
    vector<int>::type value(_value.begin(), _value.end());

    std::random_shuffle(_idx.begin(), _idx.end());
    vector<int>::type idx(_idx.begin(), _idx.end());

    sw.begin();
    thrust::scatter(
      value.begin(),
      value.end(),
      idx.begin(),
      output.begin());
    sw.end();
  }
  sw.show();

  FILE *fp = fopen(filename, "w");
  fprintf(fp, "%f\n", sw.average());
  fclose(fp);

  return 0;
}
