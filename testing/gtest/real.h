#include <thrusting/real.h>
#include <thrusting/tuple.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting;
}

TEST(Real, Create){
  real x = 1.0;
  EXPECT_EQ(real(1.0), x);
}

TEST(Real, TupleCreate){
  real2 x = real2(1.0, 2.0);
  EXPECT_EQ(thrusting::make_tuple2<real>(1.0, 2.0), x);
}

TEST(Real, SimpleArithmatic){
  EXPECT_EQ(real2(2.0, 4.0), 2 * real2(1.0, 2.0));
}
