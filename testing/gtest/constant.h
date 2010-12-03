#pragma once

#include <thrusting/vector.h>
#include <thrusting/list.h>
#include <thrust/transform.h>

#include <thrusting/functional.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting;
}

TEST(Functional, Constant){
  vector<int>::type xs(3);
  vector<size_t>::type result(3);
  thrust::transform(
    xs.begin(),
    xs.end(),
    result.begin(),
    thrusting::constant(7)); 

  size_t _ans[] = {7,7,7}; vector<size_t>::type ans(_ans, _ans+3);
  EXPECT_EQ(
    make_list(ans),
    make_list(result));
}
  
