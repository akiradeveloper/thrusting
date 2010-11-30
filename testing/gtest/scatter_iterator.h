#include <thrusting/vector.h>
#include <thrusting/list.h>

#include <thrusting/iterator/scatter_iterator.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting;
}

TEST(ScatterIterator, Test){
  int _value[10] = {1,0,1,0,1,0,1,0,1,0};
  vector<int>::type value(_value, _value+10);
  
  int _idx[10] = {0,2,4,6,8,1,3,5,7,9};
  vector<int>::type idx(_idx, _idx+10);

  int _ans[10] = {1,0,0,1,1,0,0,1,1,0};
  vector<int>::type ans(_ans, _ans+10);

  vector<size_t>::type tmp(10);
  
  EXPECT_EQ(
    make_list(ans),
    make_list(
      10,
      thrusting::make_scatter_iterator(
        value.begin(),
        value.end(),
        idx.begin(),
        tmp.begin())));
}
