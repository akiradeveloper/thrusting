#include <thrusting/vector.h>
#include <thrusting/list.h>

#include <thrusting/algorithm/safe_scatter.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting;
}

/*
  Akira Hayakawa 2011 11/30
  This test fails if we use
  thrust::scatter function
*/
TEST(Scatter, SelfSubstitution){
  int _value[] = {1,2,3,4}; vector<int>::type value(_value, _value+4);
  int _idx[] = {3,2,1,0}; vector<int>::type idx(_idx, _idx+4);

  thrusting::safe_scatter(
    value.begin(),
    value.end(),
    idx.begin(),
    value.begin()); 

  int _ans[] = {4,3,2,1}; vector<int>::type ans(_ans, _ans+4);
  
  EXPECT_EQ(
    make_list(ans),
    make_list(value));
}
