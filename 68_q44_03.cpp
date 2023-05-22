#include <iostream>

int count_swap(int n) {
  if (n == 1) {
    return 0;
  }
  int multi = 1;
  for (int i = 1; i < n; i++) {
    multi *= i;
  }
  return (n - 1) * multi + n * count_swap(n - 1);
}

int main() {
  std::cout << count_swap(7) << std::endl;

  return 0;
}