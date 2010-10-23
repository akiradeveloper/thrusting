#include <gtest/gtest.h>

#include <thrusting/thrusting.h>

#include <iostream>

//TEST(TupleTest, Plus){
//  using namespace thrusting;
//  thrusting::int2 x = make_tuple2<int>(2,3) + make_tuple2<int>(1,2);
//  EXPECT_EQ(x, make_tuple2<int>(1,1));
//} 

TEST(Tuple, Print){
  using namespace thrusting;
  std::cout << make_tuple2<int>(1,1) << std::endl;
}
