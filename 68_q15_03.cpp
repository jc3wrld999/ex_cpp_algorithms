#include <iostream>
#include <vector>

const int N = 10;      
const int STEPS = 4;  

int main() {
  std::vector<int> dp(N + 1, 0); // t회 이동으로 이동한 위치 집계
  int cnt = 0;
  dp[N] = 1;                     // 초깃값 설정

  for (int i = 0; i < N; i++) {   // 이동 횟수(최대 N)
    for (int j = 0; j <= N; j++) { // 이동
      for (int k = 1; k <= STEPS; k++) {
        if (k > j)
          break;
        dp[j - k] += dp[j];
      }
      dp[j] = 0;                // 이동을 시작한 곳은 클리어
    }
    if (i % 2 == 1) {
      cnt += dp[0];               // 짝수 회 이동으로 반대 위치에 도착
    }
  }

  std::cout << cnt << std::endl;
  
  return 0;
}