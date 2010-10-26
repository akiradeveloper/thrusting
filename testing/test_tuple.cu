#include <gtest/gtest.h>
#include <thrusting/thrusting.h>
#include <iostream>

TEST(TupleTest, Plus){
  thrust::int2 x = thrust::make_tuple2(2,3) * thrust::make_tuple2(1,2);
  EXPECT_EQ(x, thrust::make_tuple2<int>(3,5));
} 

TEST(Tuple, Print){
  thrust::int2 x = thrust::make_tuple2<int>(2,1);
  // std::cout << x << std::endl;
}
