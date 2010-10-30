#include <thrusting/tuple.h>

#include <gtest/gtest.h>
#include <thrust/device_vector.h>
#include <iostream>

using namespace thrusting::op::tuple;

TEST(Tuple, Plus){
  // T + T
  EXPECT_EQ(thrusting::make_tuple2<int>(3,5), thrusting::make_tuple2(2,3) + thrusting::make_tuple2(1,2));
} 

TEST(Tuple, Minus){
  // T - T
  EXPECT_EQ(thrusting::make_tuple2(1,1), thrusting::make_tuple2(2,3) - thrusting::make_tuple2(1,2));
}

TEST(Tuple, Multiplies){
  // T * T
  EXPECT_EQ(thrusting::make_tuple2<int>(2,6), thrusting::make_tuple2(2,3)*thrusting::make_tuple2(1,2));
}

TEST(Tuple, Multiplies2){
  // T * v
  EXPECT_EQ(thrusting::make_tuple2(2,2), thrusting::make_tuple2(1,1) * 2);
}

TEST(Tuple, Multiplies3){
  // v * T
  EXPECT_EQ(thrusting::make_tuple2(2,2), 2 * thrusting::make_tuple2(1,1));
}

TEST(Tuple, Divides){
  // T / T
  EXPECT_EQ(thrusting::make_tuple2<int>(1,2), thrusting::make_tuple2(4,2) / thrusting::make_tuple2(4,1));
}

TEST(Tuple, Divides2){
  // T / v
  EXPECT_EQ(thrusting::make_tuple2(1,1), thrusting::make_tuple2(2,2) / 2);
}
  
TEST(Tuple, OStream){
  std::cout << thrusting::make_tuple2<int>(2,1) << std::endl;
}
