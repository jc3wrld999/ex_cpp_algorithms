#include <iostream>
#include <cmath>

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  const int MAX = 500;
  int cnt = 0;

  for (int c = 1; c <= MAX / 4; c++) {
    for (int a = 1; a < c; a++) {
      for (int b = a + 1; b < c; b++) {
        if (a * a + b * b == c * c && gcd(a, b) == 1) {
          cnt++;
        }
      }
    }
  }

  std::cout << cnt << std::endl;

  return 0;
}