#include <thrusting/vector.h>
#include <thrusting/list.h>
#include <thrust/scatter.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting;
}

TEST(Thrust, Scatter){
  int _value[10] = {1,0,1,0,1,0,1,0,1,0};
  vector<int>::type value(_value, _value+10);
  
  int _idx[10] = {0,2,4,6,8,1,3,5,7,9};
  vector<int>::type idx(_idx, _idx+10);

  vector<int>::type result(10);
  
  thrust::scatter(
    value.begin(),
    value.end(),
    idx.begin(),
    result.begin());

  int _ans[10] = {1,0,0,1,1,0,0,1,1,0};
  vector<int>::type ans(_ans, _ans+10);
  
  EXPECT_EQ(
    make_list(ans),
    make_list(result));
}
