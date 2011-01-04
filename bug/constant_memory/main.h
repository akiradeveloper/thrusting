#pragma once

#include <iostream>

/*
  Initialization by this kind works
*/
__constant__ int x = 100;
__constant__ int xs[2] = {10,20};

int main(void){
  
  /*
    Initialization by cudaMemcpyToSymbol works
  */
//  int xx[2] = {1,2};
//  cudaMemcpyToSymbol(x, xx, 2*sizeof(int), 0, cudaMemcpyHostToDevice);
  
  /*
    memory space on the host.
  */
  int tmps[1];

  /*
    by default,
    cpy from device to host is choosen.
    guess it is possible to cpy from device to device (either on global or device code).
  */
  cudaMemcpyFromSymbol(tmps, xs, sizeof(int), sizeof(int)*1);
  /*
    can be print out fine.
    cout << x[0] directly without copying data on the constant memory to the host.
    std::cout can not interpret the data
    and more badly x[i] can be compiled because the syntax is correct thought it will not work fine.
    
    x is a pointer on the device space but compiler take it as one on the host space.
    the reason x[0] is 0 and x[10] is 0 is the space on the host is not initalized and occasionally allocated.

    some example like
    http://tech.ckme.co.jp/cuda_const.shtml
    access constant memory by [i] acccessor but this might be correct because
    the function is global which works on the device.
  */
  std::cout << tmps[0] << std::endl;

  int tmp;
  cudaMemcpyFromSymbol(&tmp, x, sizeof(int));
  std::cout << tmp << std::endl;

  return 0;
}
