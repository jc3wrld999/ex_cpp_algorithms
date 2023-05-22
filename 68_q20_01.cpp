#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  vector<int> magic_square = {1, 14, 14, 4, 11, 7, 6, 9,
                                   8, 10, 10, 5, 13, 2, 3, 15};

  unordered_map<int, int> memo;
  for (int i = 1; i <= magic_square.size(); ++i) {
    vector<int> comb(i);
    fill(comb.begin(), comb.begin() + i, 1);

    bool hasNext = true;
    while (hasNext) {
      int sum = 0;
      for (int j = 0; j < i; ++j) {
        sum += magic_square[j];
      }
      if (memo.find(sum) == memo.end()) {
        memo[sum] = 0;
      }
      memo[sum]++;

      hasNext = next_permutation(comb.begin(), comb.end());
    }
  }

  int max_key = 0;
  int max_value = 0;
  for (const auto& entry : memo) {
    if (entry.second > max_value) {
      max_key = entry.first;
      max_value = entry.second;
    }
  }

  cout << max_key << " " << max_value << endl;

  return 0;
}