/*
  Copied From Thrust Library v-1.3.0
  and refactored a little bit. 
  
  Akira Hayakawa, 2010
*/

#include <cstdio>
#include <cstdlib>

#include <cuda_runtime_api.h>

void usage(const char *name){
  printf("usage: %s [device_id]\n", name);
}

int main(int argc, char **argv){
  int num_devices = 0;
  int device_id = 0;

  if(argc != 2){
    usage(argv[0]);
    exit(-1);
  }

  device_id = atoi(argv[1]);

  cudaGetDeviceCount(&num_devices);

  if(device_id >= num_devices){
    printf("No available device with id %d\n", device_id);
    return -1;
  } 
   
  cudaDeviceProp properties;
  cudaGetDeviceProperties(&properties, device_id);
  printf("sm_%d%d", properties.major, properties.minor);
  return 0;
}
