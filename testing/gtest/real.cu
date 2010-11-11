#include <thrusting/dtype/real.h>
#include <thrusting/dtype/tuple/real.h>
#include <thrusting/tuple.h>

#include <gtest/gtest.h>

namespace {
  using thrusting::real;
  using thrusting::real2;
  using namespace thrusting::op;
}

TEST(real, create){
  real x = 1.0;
  EXPECT_EQ(real(1.0), x);
}

TEST(real, tuple_create){
  real2 x = real2(1.0, 2.0);
  EXPECT_EQ(thrusting::make_tuple2<real>(1.0, 2.0), x);
}

TEST(real, simple_arithmatic){
  EXPECT_EQ(real2(2.0, 4.0), 2 * real2(1.0, 2.0));
}
