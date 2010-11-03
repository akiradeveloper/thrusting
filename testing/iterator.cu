#include <thrusting/vector.h>
#include <thrusting/iterator.h>

#include <gtest/gtest.h>

TEST(Iterator, IteratorValueAt){
  int _xs[] = {1,2}; THRUSTING_VECTOR<int> xs(_xs, _xs+2);
  EXPECT_EQ(1, thrusting::iterator_value_at(0, xs.begin()));
  EXPECT_EQ(2, thrusting::iterator_value_at(1, xs.begin()));
}

TEST(Iterator, IteratorValueOf){
  int _xs[] = {1,2}; THRUSTING_VECTOR<int> xs(_xs, _xs+2);
  EXPECT_EQ(1, thrusting::iterator_value_of(xs.begin()));
}
