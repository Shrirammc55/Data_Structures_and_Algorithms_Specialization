#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}


long long euclid_GCD(long long a, long long b)
{
	if(b==0)
		return a;
	return euclid_GCD(b,a%b);
}

long long lcm_optimized(long long a, long long b){
	return ((a*b)/euclid_GCD(a,b));	
}
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_optimized(a, b) << std::endl;
  return 0;
}

