#include <thrusting/functional.h>

#include <thrust/functional.h>
#include <thrust/tuple.h>

#include <gtest/gtest.h>

TEST(Functional, Flip){
  // 4 / 2 = 2
  int x = thrusting::flip(thrust::divides<int>())(2, 4);
  EXPECT_EQ(2, x);
}

TEST(Functional, Multiplies){
  int x = thrusting::multiplies<int, int>()(2, 2);
  EXPECT_EQ(4, x);
}

TEST(Functional, divides){
  int x = thrusting::divides<int, int>()(4, 2);
  EXPECT_EQ(2, x);
}

TEST(Functional, LeftShift){
  int x = thrusting::left_shift<int, int>()(2, 2);
  EXPECT_EQ(8, x);
}

TEST(Functional, RightShift){
  int x = thrusting::right_shift<int, int>()(8, 2);
  EXPECT_EQ(2, x);
}

TEST(Functional, Bind1st){
  // 2 / 1 = 2
  int x = thrusting::bind1st(thrust::divides<int>(), 2)(1);
  EXPECT_EQ(2, x);
}

TEST(Functional, Bind2nd){
  // 4 / 2 = 2
  int x = thrusting::bind2nd(thrust::divides<int>(), 2)(4);
  EXPECT_EQ(2, x);
}

struct sum_f :public thrust::unary_function<thrust::tuple<int, int>, int> {
  int operator()(thrust::tuple<int, int> t){
    return thrust::get<0>(t) + thrust::get<1>(t);
  }
};

TEST(Functional, UnCurry){
  // 2 + 3 = 5
  int x = thrusting::uncurry(sum_f())(2,3);
  EXPECT_EQ(5, x);
}

TEST(Functional, Curry){
  // 2 + 3 = 5
  int x = thrusting::curry(thrust::plus<int>())(thrust::make_tuple(2,3));
  EXPECT_EQ(5, x);
}

TEST(Functional, Compose){
  // -1 -> 1 -> 1
  int x = thrusting::compose(thrust::negate<int>(), thrust::identity<int>())(-1);
  EXPECT_EQ(1, x);
}
