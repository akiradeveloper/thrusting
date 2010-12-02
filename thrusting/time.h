#pragma once

#include <ctime>
#include <iostream>
#include <string>

#include <thrust/host_vector.h>
#include <thrusting/list.h>

namespace thrusting {

class stopwatch {

  std::string _title;
  double _begin;
  thrust::host_vector<double> _times; 

public:

  stopwatch(std::string name)
  :_begin(0), _title(name)
  {
    _times = thrust::host_vector<double>(0);
  }
  
  double CPUTime(){
    cudaThreadSynchronize();
    double t = (double) clock();
    return t / CLOCKS_PER_SEC;
  }

  void begin(){
    _begin = CPUTime();
  }
   
  void end(){
    _times.push_back( CPUTime() - _begin );
  }

  double average(){
    return thrust::reduce(_times.begin(), _times.end()) / _times.size();
  }
   
  void show(){
    std::cout << "--- " << _title << " ---" << std::endl;
    std::cout << "Average: " << average() << std::endl;
    std::cout << "Times:" << std::endl;
    std::cout << make_list(_times) << std::endl;
  }
};

} // END thrusting
