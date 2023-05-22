#include <iostream>
#include <vector>
using namespace std;

const int N = 4;

int search(const vector<int>& rows) {
  // 모든 행을 탐색하면 종료
  if (rows.size() == N) {
    return 1;
  }

  int count = 0;
  for (int row = 0; row < (1 << N); row++) {
    // 네 모서리에 ○과 ×가 교대로 되어 있는지 확인
    bool is_cross = false;
    for (int r : rows) {
      if ((row & ~r) > 0 && (~row & r) > 0) {
        is_cross = true;
        break;
      }
    }
    if (!is_cross) {
      vector<int> next_rows = rows;
      next_rows.push_back(row);
      count += search(next_rows);
    }
  }

  return count;
}

int main() {
  cout << search({}) << endl;

  return 0;
}