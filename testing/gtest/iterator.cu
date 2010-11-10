#include <thrusting/tuple.h>
#include <thrusting/list.h>
#include <thrusting/vector.h>
#include <thrusting/iterator.h>
#include <thrusting/iterator/zip_iterator.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting::op;
}

TEST(iterator, iterator_value_at){
  int _xs[] = {1,2}; THRUSTING_VECTOR<int> xs(_xs, _xs+2);
  EXPECT_EQ(1, thrusting::iterator_value_at(0, xs.begin()));
  EXPECT_EQ(2, thrusting::iterator_value_at(1, xs.begin()));
}

TEST(iterator, iterator_value_of){
  int _xs[] = {1,2}; THRUSTING_VECTOR<int> xs(_xs, _xs+2);
  EXPECT_EQ(1, thrusting::detail::iterator_value_of(xs.begin()));
}

TEST(iterator, advance){
  int _xs[] = {1,2}; THRUSTING_VECTOR<int> xs(_xs, _xs+2);
  int _ys[] = {3,4}; THRUSTING_VECTOR<int> ys(_ys, _ys+2);
  EXPECT_EQ(thrust::make_tuple(2,4), 
    thrusting::detail::iterator_value_of(
      thrusting::advance(1, thrusting::make_zip_iterator(xs.begin(), ys.begin()))));
}

TEST(iterator, alloc_at){
  int _xs[] = {1,2}; THRUSTING_VECTOR<int> xs(_xs, _xs+2);
  int _ys[] = {3,4}; THRUSTING_VECTOR<int> ys(_ys, _ys+2);
  thrusting::alloc_at(1, thrusting::make_zip_iterator(xs.begin(), ys.begin()), thrust::make_tuple(5,6));
  int _ans_xs[] = {1,5}; THRUSTING_VECTOR<int> ans_xs(_ans_xs, _ans_xs+2); 
  int _ans_ys[] = {3,6}; THRUSTING_VECTOR<int> ans_ys(_ans_ys, _ans_ys+2); 
  EXPECT_EQ(thrusting::make_list(ans_xs), thrusting::make_list(xs));
  EXPECT_EQ(thrusting::make_list(ans_ys), thrusting::make_list(ys));
}
