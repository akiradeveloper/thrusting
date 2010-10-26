#include <gtest/gtest.h>

#include <thrusting/thrusting.h>
#include <thrust/device_vector.h>

TEST(Parallel, Ostream){
  int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 
  std::cout << thrust::make_parallel(2, d_xs.begin()) << std::endl;
}

TEST(Parallel, Equality){
 int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 
 EXPECT_EQ(
   thrust::make_parallel(2, d_xs.begin()),
   thrust::make_parallel(2, d_xs.begin()));
}

TEST(Parallel, Addtion){
  int xs[] = {1,2}; thrust::device_vector<int> d_xs(xs, xs+2); 
  int ys[] = {3,4}; thrust::device_vector<int> d_ys(ys, ys+2); 
  int zs[] = {4,6}; thrust::device_vector<int> d_zs(zs, zs+2); 
  thrust::make_parallel(2, d_xs.begin()) += d_ys.begin();
  EXPECT_EQ(
    thrust::make_parallel(2, d_xs.begin()),
    thrust::make_parallel(2, d_zs.begin()));
}

