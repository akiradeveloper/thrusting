#include <thrusting/vector.h>
#include <thrusting/list.h>

#include <thrusting/algorithm/safe_gather.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting;
}

/*
  This test fails if we use thrust::gather
*/
TEST(GatherBySeq, SelfSubstitution){
  int _idx[10] = {3,2,1,0};
  vector<int>::type idx(_idx, _idx+4);

  int _value[10] = {1,2,3,4};
  vector<int>::type value(_value, _value+4);

  vector<int>::type result(4);
  
  thrusting::safe_gather(
    idx.begin(),
    idx.end(),
    value.begin(),
    value.begin()); // self substitution
  
  int _answer[10] = {4,3,2,1};
  vector<int>::type answer(_answer, _answer+4);

  EXPECT_EQ(
    thrusting::make_list(answer),
    thrusting::make_list(value));
}
