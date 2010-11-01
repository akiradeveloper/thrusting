#include <thrusting/iterator.h>
#include <thrusting/iterator/zip_iterator.h>
#include <thrusting/vector.h>

#include <thrusting/tuple.h>

#include <gtest/gtest.h>

TEST(ZipIterator, Reference){
  int _xs[] = {1,2}; THRUSTING_VECTOR<int> xs(_xs, _xs+2);
  int _ys[] = {3,4}; THRUSTING_VECTOR<int> ys(_ys, _ys+2);

  EXPECT_EQ(
    thrust::make_tuple(1,3), 
    thrusting::iterator_value_at(0, thrusting::make_zip_iterator(xs.begin(), ys.begin())));

  EXPECT_EQ(
    thrust::make_tuple(2,4), 
    thrusting::iterator_value_at(1, thrusting::make_zip_iterator(xs.begin(), ys.begin())));
}
