#pragma once

#include <thrusting/random/engine.h>
#include <thrusting/random/distribution.h>

#include <thrusting/functional.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting;
}

TEST(Engine, Fast){
  float x = compose(
    uniform_real_distribution<float>(3, 5), 
    fast_rng_generator<int>())(10000);

  EXPECT_GE(x, 3);
  EXPECT_LT(x, 5);
}

TEST(Engine, Discard){
  float x = compose(
    uniform_real_distribution<float>(3, 5), 
    rng_generator<int>(777))(10000);

  EXPECT_GE(x, 3);
  EXPECT_LT(x, 5);
}
