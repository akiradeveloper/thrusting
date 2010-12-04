#pragma once

#include <thrusting/random/generate.h>
#include <thrusting/vector.h>
#include <thrusting/list.h>
#include <thrusting/functional.h>

#include <gtest/gtest.h>

namespace {
  using namespace thrusting;
}

TEST(Generate, Test){
  vector<float>::type output(10);
 
  thrusting::generate(
    output.begin(),
    output.end(),
    thrusting::constant(1));
//    compose(
//      thrusting::uniform_real_distribution<float>(0, 10),
//      fast_rng_generator<int>()));

  std::cout << make_list(output) << std::endl;
}
