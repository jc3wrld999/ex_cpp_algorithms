#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

const int MAX = 500;

int main() {
  std::vector<std::vector<int>> answer;
  
  for (int c = 1; c <= MAX / 4; c++) { // 정사각형 한 변 선택
    for (int x = 1; x < c; x++) { // 작은 변 선택
      for (int y = x + 1; y < c; y++) { // 큰 변 선택
        int a = x * (2 * c - x);
        int b = y * (2 * c - y);
        if (a + b == c * c) {
          answer.push_back({1, b / a, c * c / a});
        }
      }
    }
  }

  // 중복제거
//   std::vector<std::vector<int>> uniqueAnswer;
//   for (const auto& item : answer) {
//     if (std::find(uniqueAnswer.begin(), uniqueAnswer.end(), item) == uniqueAnswer.end()) {
//       uniqueAnswer.push_back(item);
//     }
//   }
  std::unordered_set<std::vector<int>> uniqueAnswer(answer.begin(), answer.end());

  std::cout << uniqueAnswer.size() << std::endl;

  return 0;
}