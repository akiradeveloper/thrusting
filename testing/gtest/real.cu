#include <thrusting/dtype/real.h>
#include <thrusting/dtype/n_typedef/real.h>
#include <thrusting/tuple.h>

#include <gtest/gtest.h>

#include <thrusting/op/tuple.h>
namespace {
  using namespace thrusting::op::tuple;
}

TEST(Real, Create){
  thrusting::real x = 1.0;
  EXPECT_EQ(1.0, x);
}

TEST(Real, Tuple){
  thrusting::real2 x = thrusting::make_tuple2<thrusting::real>(1.0, 2.0);
  EXPECT_EQ(thrusting::make_tuple2(1.0,2.0), x);
}

TEST(Real, Arithmetic){
  EXPECT_EQ(thrusting::make_tuple2<thrusting::real>(2.0, 4.0), 2 * thrusting::make_tuple2<thrusting::real>(1.0, 2.0));
}
