#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int count = 0;
  std::vector<int> ary = {1, 2, 3, 4, 5, 6, 7};

  do {
    for (int i = 0; i < ary.size(); i++) {
      if (ary[i] != i + 1) {
        int j = std::find(ary.begin(), ary.end(), i + 1) - ary.begin();
        std::swap(ary[i], ary[j]);
        count++;
      }
    }
  } while (std::next_permutation(ary.begin(), ary.end()));

  std::cout << count << std::endl;

  return 0;
}