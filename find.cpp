#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> vec = {1, 2, 3, 4, 5};

  // 3의 위치를 찾는다.
  auto iter = find(vec.begin(), vec.end(), 4);

  if (iter != vec.end()) {
    cout << "3 is found at index: " << *iter - 1 << endl;
  } else {
    cout << "3 is not found" << endl;
  }

  return 0;
}