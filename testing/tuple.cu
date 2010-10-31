#include <thrusting/tuple.h>
#include <thrusting/dtype.h>

#include <gtest/gtest.h>
#include <iostream>

TEST(Tuple, Plus){
  // T + T
  EXPECT_EQ(thrusting::make_tuple2(3,5), thrusting::make_tuple2(2,3) + thrusting::make_tuple2(1,2));
} 

TEST(Tuple, Minus){
  // T - T
  EXPECT_EQ(thrusting::make_tuple2(1,1), thrusting::make_tuple2(2,3) - thrusting::make_tuple2(1,2));
}

TEST(Tuple, Multiplies){
  // T * T
  EXPECT_EQ(thrusting::make_tuple2(2,6), thrusting::make_tuple2(2,3)*thrusting::make_tuple2(1,2));
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
  EXPECT_EQ(thrusting::make_tuple2(1,2), thrusting::make_tuple2(4,2) / thrusting::make_tuple2(4,1));
}

TEST(Tuple, Divides2){
  // T / v
  EXPECT_EQ(thrusting::make_tuple2(1,1), thrusting::make_tuple2(2,2) / 2);
}
  
TEST(Tuple, OStream){
  std::cout << thrusting::make_tuple2(2,1) << std::endl;
}

TEST(Tuple, ArithmaticOrdering){
  thrusting::int2 x = thrusting::make_tuple2(1,2);
  thrusting::int2 y = thrusting::make_tuple2(3,4);
  thrusting::int2 z = thrusting::make_tuple2(5,6);
  
  EXPECT_EQ(thrusting::make_tuple2(16, 26), x + y * z);
  EXPECT_EQ(thrusting::make_tuple2(8, 20), x * (y+z));
}
