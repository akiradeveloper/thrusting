#include <gtest/gtest.h>

#include <thrusting/thrusting.h>
// #include <thrusting/parallel.h>
#include <thrust/device_vector.h>

TEST(Parallel, Ostream){
  int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 
  // std::cout << thrust::make_parallel(2, d_xs.begin()) << std::endl;
}

TEST(Parallel, Equality){
 int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 

 int ys[] = {1,2}; thrust::device_vector<int> d_ys(ys, ys+2); 
 EXPECT_EQ(
   thrusting::make_parallel(2, d_xs.begin()),
   thrusting::make_parallel(2, d_ys.begin()));

 int zs[] = {1,3}; thrust::device_vector<int> d_zs(zs, zs+2); 
 EXPECT_NE(
   thrusting::make_parallel(2, d_xs.begin()),
   thrusting::make_parallel(2, d_zs.begin())); 
}

TEST(Parallel, Addtion){
  int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 
  int ys[] = {3,4}; thrust::device_vector<int> d_ys(ys, ys+2); 
  int zs[] = {4,7}; thrust::device_vector<int> d_zs(zs, zs+2); 
  
  thrusting::make_parallel(2, d_xs.begin()) += d_ys.begin();
  EXPECT_NE(
    thrusting::make_parallel(2, d_xs.begin()),
    thrusting::make_parallel(2, d_zs.begin()));
}
