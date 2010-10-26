#include <gtest/gtest.h>
#include <thrusting/thrusting.h>

TEST(Parallel, Ostream){
  thrust::device_vector<int> xs = thrust::make_device_vector<int>(2, 1, 2);
  std::cout << thrust::make_parallel(2, xs.begin()) << std::endl;
}
