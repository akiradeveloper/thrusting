#include <thrusting/tuple.h>
#include <thrusting/dtype/tuple/int.h>

#include <gtest/gtest.h>
#include <iostream>

namespace {
  using namespace thrusting::op;
}

TEST(Tuple, Plus){
  // T + T
  EXPECT_EQ(thrusting::make_tuple2(3,5), thrusting::make_tuple2(2,3) + thrusting::make_tuple2(1,2));
} 

TEST(Tuple, Minus){
  // T - T
  EXPECT_EQ(thrusting::make_tuple2(1,1), thrusting::make_tuple2(2,3) - thrusting::make_tuple2(1,2));
}

TEST(Tuple, Multiplies2){
  // v * T
  EXPECT_EQ(thrusting::make_tuple2(2,2), 2 * thrusting::make_tuple2(1,1));
}

TEST(Tuple, Divides){
  // T / v
  EXPECT_EQ(thrusting::make_tuple2(1,1), thrusting::make_tuple2(2,2) / 2);
}

TEST(Tuple, MakeString){
  EXPECT_EQ("(1, 2)", thrusting::make_string(thrusting::make_tuple2(1,2)));
}
  
TEST(Tuple, OStream){
  std::cout << thrusting::make_tuple2(1,2) << std::endl;
}

TEST(Tuple, ArithmaticOrdering){
  thrusting::int2 x = thrusting::make_tuple2(1,2);
  thrusting::int2 y = thrusting::make_tuple2(3,4);
  
  EXPECT_EQ(thrusting::make_tuple2(7, 10), x + 2 * y);
  EXPECT_EQ(thrusting::make_tuple2(8, 12), 2 * (x + y));
}
