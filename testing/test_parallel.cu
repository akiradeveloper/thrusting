#include <gtest/gtest.h>

#include <thrusting/thrusting.h>
#include <thrust/device_vector.h>
#include <iostream>
#include <string>
#include <thrust/equal.h>

TEST(Parallel, Ostream){
  int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 
  std::cout << thrust::make_parallel(2, d_xs.begin()) << std::endl;
}

TEST(Parallel, Equality){
 int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 

 int ys[] = {1,2}; thrust::device_vector<int> d_ys(ys, ys+2); 
 EXPECT_EQ(
   thrust::make_parallel(2, d_xs.begin()),
   thrust::make_parallel(2, d_ys.begin()));

 int zs[] = {1,3}; thrust::device_vector<int> d_zs(zs, zs+2); 
 EXPECT_NE(
   thrust::make_parallel(2, d_xs.begin()),
   thrust::make_parallel(2, d_zs.begin())); 
}

#include <thrust/functional.h>

TEST(Parallel, Addtion){
  int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 
  int ys[] = {3,4}; thrust::device_vector<int> d_ys(ys, ys+2); 
  int zs[] = {4,7}; thrust::device_vector<int> d_zs(zs, zs+2); 
  
  thrust::make_parallel(2, d_xs.begin()) += d_ys.begin();
  EXPECT_NE(
    thrust::make_parallel(2, d_xs.begin()),
    thrust::make_parallel(2, d_zs.begin()));
}

template<typename T>
std::ostream &operator<<(std::ostream &os, thrust::device_vector<T> xs){
  return os << "akira";
}

#include <cassert>

TEST(Vector, Equality){
  int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 
  int ys[] = {1,3}; thrust::device_vector<int> d_ys(ys, ys+2); 
  // assert(d_xs == d_ys);
}
  
