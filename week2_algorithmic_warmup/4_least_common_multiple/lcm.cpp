#include <iostream>

long long gcd(long long a, long long b) {
  while(a != b) {
    if(a > b)
      a -= b;
    else
      b -= a;
  }
  
  return a;
}

long long lcm_fast(long long a, long long b) {
  if (a == 0 || b == 0) {
    return 0;
  }
  long long l = a*b / gcd(a, b);
  return l;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
