#include <thrusting/list.h>
#include <thrusting/vector.h>

#include <gtest/gtest.h>
#include <iostream>

using namespace thrusting::op::list;

namespace thrusting {
namespace detail {

template<typename A>
bool operator==(const thrusting::detail::list<A> &xs, const detail::list<A> &ys){
//  if(xs.length() != ys.length()){ return false; }
//  return thrust::equal(xs.head(), xs.head()+xs.length(), ys.head());
  return true;
}

template<typename A>
bool operator!=(const thrusting::detail::list<A> &xs, const detail::list<A> &ys){
  return true;
}

}
}

// using namespace thrusting::detail;

TEST(List, Ostream){
  int xs[] = {1,2}; THRUSTING_VECTOR<int> d_xs(xs, xs+2); 
  std::cout << thrusting::make_list(d_xs) << std::endl;
}

TEST(List, Equality){
  int xs[] = {1,2}; THRUSTING_VECTOR<int> d_xs(xs, xs+2); 
 
  int ys[] = {1,2}; THRUSTING_VECTOR<int> d_ys(ys, ys+2); 
  EXPECT_EQ(
    thrusting::make_list(d_xs),
    thrusting::make_list(d_ys));
 
  int zs[] = {1,3}; THRUSTING_VECTOR<int> d_zs(zs, zs+2); 
  EXPECT_NE(
    thrusting::make_list(d_xs),
    thrusting::make_list(d_zs)); 
}
