#pragma once

#ifdef THRUSTING_USE_DEVICE_VECTOR
  #define THRUSTING_VECTOR thrust::device_vector 
#else
  #define THRUSTING_VECTOR thrust::host_vector
#endif
