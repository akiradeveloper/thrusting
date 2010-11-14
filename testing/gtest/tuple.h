#include <thrusting/tuple.h>
#include <thrusting/dtype/tuple/int.h>
#include <thrusting/iterator.h>
#include <thrusting/iterator/zip_iterator.h>

#include <iostream>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting::op;
}

TEST(tuple, plus){
  // T + T
  EXPECT_EQ(thrusting::make_tuple2(3,5), thrusting::make_tuple2(2,3) + thrusting::make_tuple2(1,2));
} 

TEST(tuple, minus){
  // T - T
  EXPECT_EQ(thrusting::make_tuple2(1,1), thrusting::make_tuple2(2,3) - thrusting::make_tuple2(1,2));
}

TEST(tuple, multiplies){
  // v * T
  EXPECT_EQ(thrusting::make_tuple2(2,2), 2 * thrusting::make_tuple2(1,1));
}

TEST(tuple, divides){
  // T / v
  EXPECT_EQ(thrusting::make_tuple2(1,1), thrusting::make_tuple2(2,2) / 2);
}

TEST(tuple, make_string){
  EXPECT_EQ("(1, 2)", thrusting::make_string(thrusting::make_tuple2(1,2)));
}
  
TEST(tuple, ostream){
  std::cout << thrusting::make_tuple2(1,2) << std::endl;
}

TEST(tuple, arithmatic_priority){
  thrusting::int2 x = thrusting::make_tuple2(1,2);
  thrusting::int2 y = thrusting::make_tuple2(3,4);
  
  EXPECT_EQ(thrusting::make_tuple2(7, 10), x + 2 * y);
  EXPECT_EQ(thrusting::make_tuple2(8, 12), 2 * (x + y));
}
