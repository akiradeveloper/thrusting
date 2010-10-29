#include <thrust/functional.h>

template<typename A, typename B>
B adapter(A x, thrust::unary_function<A, B> f){
  return f(x);
}

int main(void){
  adapter(1, thrust::negate<int>()); 
  return 0;
}
