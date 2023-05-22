#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
using namespace std;

const int N = 4;

unordered_map<vector<int>, int> count_map;

void search() {
  // 각 행을 수치로 설정
  for (int rows = 0; rows < (1 << N); rows++) {
    vector<int> col_count(N, 0);

    // 각 열의 ○의 수를 카운트
    for (int c = 0; c < N; c++) {
      for (int r = 0; r < N; r++) {
        if ((rows & (1 << r)) > 0) {
          col_count[c] += 1;
        }
      }
    }

    // 각 행의 ○의 수를 카운트
    vector<int> row_count(N, 0);
    for (int r = 0; r < N; r++) {
      row_count[r] = bitset<N>(rows).count();
    }

    // 해시에 행과 열의 카운트로 집계
    vector<int> key = row_count;
    key.insert(key.end(), col_count.begin(), col_count.end());
    if (count_map.find(key) == count_map.end()) {
      count_map[key] = 0;
    }
    count_map[key] += 1;
  }
}

int main() {
  search();

  // 한 가지로 배치할 수 있는 것을 출력
  int unique_count = 0;
  for (const auto& item : count_map) {
    if (item.second == 1) {
      unique_count++;
    }
  }

  cout << unique_count << endl;

  return 0;
}