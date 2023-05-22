#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;
const int MAX = 500;

int main() {
  vector<vector<int>> answer;
  
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
//   vector<vector<int>> uniqueAnswer;
//   for (const auto& item : answer) {
//     if (find(uniqueAnswer.begin(), uniqueAnswer.end(), item) == uniqueAnswer.end()) {
//       uniqueAnswer.push_back(item);
//     }
//   }
  unordered_set<vector<int>> uniqueAnswer(answer.begin(), answer.end());

  cout << uniqueAnswer.size() << endl;

  return 0;
}