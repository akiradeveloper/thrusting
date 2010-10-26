#include <gtest/gtest.h>
#include <thrusting/thrusting.h>
#include <iostream>

TEST(Tuple, Plus){
  thrust::int2 x = thrust::make_tuple2(2,3) + thrust::make_tuple2(1,2);
  EXPECT_EQ(thrust::make_tuple2<int>(3,5), x);
} 

TEST(Tuple, Multiplies){
  EXPECT_EQ(thrust::make_tuple2<int>(2,6), thrust::make_tuple2(2,3)*thrust::make_tuple2(1,2));
}

TEST(Tuple, Devides){
  EXPECT_EQ(thrust::make_tuple<int>(1,2), thrust::make_tuple2(4,2) / thrust::make_tuple(4,1));
}

TEST(Tuple, Print){
  thrust::int2 x = thrust::make_tuple2<int>(2,1);
  // std::cout << x << std::endl;
}
