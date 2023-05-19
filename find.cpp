#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};

  // 3의 위치를 찾는다.
  auto iter = std::find(vec.begin(), vec.end(), 4);

  if (iter != vec.end()) {
    std::cout << "3 is found at index: " << *iter - 1 << std::endl;
  } else {
    std::cout << "3 is not found" << std::endl;
  }

  return 0;
}