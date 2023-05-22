#include <iostream>
using namespace std;

int set_tap(int remain) {
  if (remain == 1) {
    return 1;
  }
  int cnt = 0;
  // 2구
  for (int i = 1; i <= remain / 2; ++i) {
    if (remain - i == i) {
      cnt += set_tap(i) * (set_tap(i) + 1) / 2;
    } else {
      cnt += set_tap(remain - i) * set_tap(i);
    }
  }
  // 3구
  for (int i = 1; i <= remain / 3; ++i) {
    for (int j = i; j <= (remain - i) / 2; ++j) {
      if ((remain - (i + j) == i) && (i == j)) {
        cnt += set_tap(i) * (set_tap(i) + 1) * (set_tap(i) + 2) / 6;
      } else if (remain - (i + j) == i) {
        cnt += set_tap(i) * (set_tap(i) + 1) * set_tap(j) / 2;
      } else if (i == j) {
        cnt += set_tap(remain - (i + j)) * set_tap(i) * (set_tap(i) + 1) / 2;
      } else if (remain - (i + j) == j) {
        cnt += set_tap(j) * (set_tap(j) + 1) * set_tap(i) / 2;
      } else {
        cnt += set_tap(remain - (i + j)) * set_tap(j) * set_tap(i);
      }
    }
  }
  return cnt;
}

int main() {
  int N = 20;
  cout << set_tap(N) << endl;
  return 0;
}