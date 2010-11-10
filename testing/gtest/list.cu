#include <thrusting/list.h>
#include <thrusting/vector.h>

#include <gtest/gtest.h>
#include <iostream>

TEST(list, make_string){
  int _xs[] = {1,2}; THRUSTING_VECTOR<int> xs(_xs, _xs+2); 
  EXPECT_EQ("[1, 2]", thrusting::make_string(thrusting::make_list(xs)));
}

TEST(list, ostream){
  int _xs[] = {1,2}; THRUSTING_VECTOR<int> xs(_xs, _xs+2); 
  std::cout << thrusting::make_list(xs) << std::endl;
}

TEST(list, equality){
  int _xs[] = {1,2}; THRUSTING_VECTOR<int> xs(_xs, _xs+2); 
 
  int _ys[] = {1,2}; THRUSTING_VECTOR<int> ys(_ys, _ys+2); 
  EXPECT_EQ(
    thrusting::make_list(xs),
    thrusting::make_list(ys));
 
  int _zs[] = {1,3}; THRUSTING_VECTOR<int> zs(_zs, _zs+2); 
  EXPECT_NE(
    thrusting::make_list(xs),
    thrusting::make_list(zs)); 
}
