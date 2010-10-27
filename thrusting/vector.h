#pragma once

#ifdef THRUSTING_USING_DEVICE_VECTOR
  #define thrust::device_vector thrusting::vector
#else
  #define thrust::host_vector thrusting::vector
#endif
