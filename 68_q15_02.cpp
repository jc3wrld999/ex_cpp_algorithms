#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 10;    // Number of steps
const int STEPS = 4; // Maximum number of steps that can be taken

unordered_map<pair<int, int>, int, hash<pair<int, int>>> memo;

int move(int a, int b) {
  if (a > b) {
    return 0;
  } else if (a == b) {
    return 1;
  }
  
  // 메모 확인
  pair<int, int> key(a, b);
  if (memo.find(key) != memo.end()) {
    return memo[key];
  }
  
  int cnt = 0;
  for (int da = 1; da <= STEPS; da++) {
    for (int db = 1; db <= STEPS; db++) {
      cnt += move(a + da, b - db); 
    }
  }
  // 메모
  memo[key] = cnt;
  return cnt;
}

int main() {
  cout << move(0, N) << endl;
  
  return 0;
}