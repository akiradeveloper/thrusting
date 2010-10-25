#include <gtest/gtest.h>
#include <thrusting/thrusting.h>
#include <iostream>

// letting this function in std namespace and compilation scceeded, why?
//template<typename T0, typename T1>
//std::ostream &operator<<(std::ostream &os, const thrust::tuple<T0, T1> &x){
//  std::stringstream ss;
//  ss << "(" << 
//thrust::get<0>(x)
// << ", " << 
//thrust::get<1>(x)
// << ")";
//  os << ss.str();
//  return os;
//}

TEST(TupleTest, Plus){
  // ADL not effective to alias.
  // thrusting int2 aliased to thrust::tuple<int, int> and ADL failed.
  thrusting::int2 x = thrusting::make_tuple2(2,3) * thrusting::make_tuple2(1,2);
  EXPECT_EQ(x, thrusting::make_tuple2<int>(3,5));
} 

TEST(Tuple, Print){
  thrusting::int2 x = thrust::make_tuple2<int>(2,1);
  // std::cout << x << std::endl;
}
