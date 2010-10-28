#include <thrust/device_vector.h>
#include <thrusting/vector.h>

int main(void){
  THRUSTING_VECTOR<int> xs(10);
  xs.push_back(200);
  return 0;
}
