#include <thrusting/vector.h>
#include <thrusting/iterator/gather_iterator.h>
#include <thrusting/list.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting;
}

TEST(GatherIterator, Test){
  int _input[] = {1,0}; vector<int>::type input(_input, _input+2);
  int _map[] = {1,2,3}; vector<int>::type map(_map, _map+3);
  
  int _ans[] = {2,1}; vector<int>::type ans(_ans, _ans+2);

  EXPECT_EQ(
    make_list(ans),
    make_list(2, make_gather_iterator(input, map)));
}
