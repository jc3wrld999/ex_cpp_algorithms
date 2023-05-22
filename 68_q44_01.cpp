#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> combinations(const vector<int>& nums, int k) {
  vector<vector<int>> result;
  vector<bool> chosen(nums.size(), false);
  vector<int> current;
  backtrack(nums, k, 0, chosen, current, result);
  return result;
}

void backtrack(const vector<int>& nums, int k, int start, vector<bool>& chosen, vector<int>& current, vector<vector<int>>& result) {
  if (k == 0) {
    result.push_back(current);
    return;
  }

  for (int i = start; i < nums.size(); i++) {
    if (!chosen[i]) {
      chosen[i] = true;
      current.push_back(nums[i]);
      backtrack(nums, k - 1, i + 1, chosen, current, result);
      current.pop_back();
      chosen[i] = false;
    }
  }
}

int main() {
  int N = 7;
  unordered_map<vector<int>, int> checked;
  checked[{1, 2, 3, 4, 5, 6, 7}] = 0;
  vector<vector<int>> check = {{1, 2, 3, 4, 5, 6, 7}};
  int depth = 0;

  while (!check.empty()) {
    vector<vector<int>> next_check;
    for (int i = 0; i < N - 1; i++) {
      for (int j = i + 1; j < N; j++) {
        for (const auto& c : check) {
          vector<int> d = c;
          swap(d[i], d[j]);
          if (checked.find(d) == checked.end()) {
            checked[d] = depth + 1;
            next_check.push_back(d);
          }
        }
      }
    }
    check = next_check;
    depth += 1;
  }

  int sum = 0;
  for (const auto& entry : checked) {
    sum += entry.second;
  }

  cout << sum << endl;

  return 0;
}