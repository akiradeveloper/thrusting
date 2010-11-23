#include <thrust/gather.h>
#include <thrusting/vector.h>
#include <thrusting/list.h>

#include <gtest/gtest.h>

TEST(Thrust, Gather){
  int _idx[10] = {0,2,4,6,8,1,3,5,7,9};
  THRUSTING_VECTOR<int> idx(_idx, _idx+10);

  int _value[10] = {1,0,1,0,1,0,1,0,1,0};
  THRUSTING_VECTOR<int> value(_value, _value+10);

  THRUSTING_VECTOR<int> result(10);
  
  thrust::gather(
    idx.begin(),
    idx.end(),
    value.begin(),
    result.begin());
  
  int _answer[10] = {1,1,1,1,1,0,0,0,0,0};
  THRUSTING_VECTOR<int> answer(_answer, _answer+10);
  EXPECT_EQ(
    thrusting::make_list(answer),
    thrusting::make_list(result));
}

#include <thrust/scatter.h>
#include <iostream>

/*
  What is scatter?
  Who can understand?
*/
TEST(Thrust, Scatter){
  int _value[10] = {1,0,1,0,1,0,1,0,1,0};
  THRUSTING_VECTOR<int> value(_value, _value+10);
  
  int _idx[10] = {0,2,4,6,8,1,3,5,7,9};
  THRUSTING_VECTOR<int> idx(_idx, _idx+10);

  THRUSTING_VECTOR<int> result(10);
  
  thrust::scatter(
    value.begin(),
    value.end(),
    idx.begin(),
    result.begin());

  std::cout << thrusting::make_list(result) << std::endl;
}
