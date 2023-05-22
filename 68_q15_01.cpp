#include <iostream>
using namespace std;
const int N = 10;    // Number of steps
const int STEPS = 4; // Maximum number of steps that can be taken

int move(int a, int b) {
  if (a > b) {
    // A가 B보다 위에 있으면 종료
    return 0;
  } else if (a == b) {
    // 같은 단에서 멈추면 수를 셈
    return 1;
  }
  
  int cnt = 0;
  for (int da = 1; da <= STEPS; da++) {
    for (int db = 1; db <= STEPS; db++) {
      cnt += move(a + da, b - db); // 재귀적으로 탐색
    }
  }
  return cnt;
}

int main() {
  // A는 0의 위치에서 B는 N의 위치에서 스타트
  cout << move(0, N) << endl;
  
  return 0;
}