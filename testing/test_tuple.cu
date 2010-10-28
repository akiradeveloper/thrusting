#include <gtest/gtest.h>
#include <thrust/device_vector.h>
#include <thrusting/thrusting.h>

TEST(Tuple, Plus){
  thrusting::int2 x = thrusting::make_tuple2(2,3) + thrusting::make_tuple2(1,2);
  EXPECT_EQ(thrusting::make_tuple2<int>(3,5), x);
} 

TEST(Tuple, Multiplies){
  EXPECT_EQ(thrusting::make_tuple2<int>(2,6), thrusting::make_tuple2(2,3)*thrusting::make_tuple2(1,2));
}

TEST(Tuple, Devides){
  EXPECT_EQ(thrusting::make_tuple2<int>(1,2), thrusting::make_tuple2(4,2)/thrusting::make_tuple2(4,1));
}

TEST(Tuple, Print){
  thrusting::int2 x = thrusting::make_tuple2<int>(2,1);
  // std::cout << x << std::endl;
}
