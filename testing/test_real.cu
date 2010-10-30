#include <thrusting/real.h>

#include <gtest/gtest.h>

TEST(Real, Create){
  thrusting::real x = 1.0;
}

TEST(Real, Tuple){
  thrusting::real2 x = thrusting::make_real2(1.0, 2.0);
}

TEST(Real, Arithmetic){
  EXPECT_EQ(thrusting::make_real2(2.0, 4.0), 2 * thrusting::make_real2(1.0, 2.0));
}
