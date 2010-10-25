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
  using namespace thrusting;
  EXPECT_EQ(make_tuple2<int>(2,3) + make_tuple2<int>(1,2), make_tuple2<int>(3,5));
} 

TEST(Tuple, Print){
  using namespace thrusting;
  const thrusting::int2 const x = make_tuple2<int>(2,1);
  // std::cout << x << std::endl;
}
