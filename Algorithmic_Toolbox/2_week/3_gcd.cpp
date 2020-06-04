#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long euclid_GCD(long long a, long long b)
{
	if(b==0)
		return a;
	return euclid_GCD(b,a%b);
}
int main() {
  long long a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout<<euclid_GCD(a,b)<<std::endl;
  return 0;
}

