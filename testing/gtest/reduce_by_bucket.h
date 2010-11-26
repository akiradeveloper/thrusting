#include <thrusting/vector.h>
#include <thrusting/list.h>
#include <thrusting/algorithm/reduce_by_bucket.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting;
}

TEST(ReduceByBucket, Test){
  size_t n_value = 5;
  int _idx[] = {1,1,2,2,2}; vector<int>::type idx(_idx, _idx+n_value);
  int _value[] = {1,2,3,4,5}; vector<int>::type value(_value, _value+n_value);
  
  size_t n_bucket = 4; 
  vector<int>::type cnt_output(n_bucket);
  vector<int>::type value_output(n_bucket);
  vector<int>::type tmp1(n_bucket);
  vector<int>::type tmp2(n_bucket);

  int null_value = 10000;

  thrusting::reduce_by_bucket(
    n_value,
    idx.begin(),
    value.begin(),
    n_bucket,
    cnt_output.begin(),
    value_output.begin(),
    tmp1.begin(),
    tmp2.begin(),
    null_value); 

  int _ans_cnt[] = {0,2,3,0}; vector<int>::type ans_cnt(_ans_cnt, _ans_cnt+n_bucket);
  int _ans_value[] = {10000,3,12,10000}; vector<int>::type ans_value(_ans_value, _ans_value+n_bucket);
  
  EXPECT_EQ(
    make_list(ans_cnt),
    make_list(cnt_output));

  EXPECT_EQ(
    make_list(ans_value),
    make_list(value_output));
}
