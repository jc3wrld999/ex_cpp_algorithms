#include <iostream>
#include <vector>

int N = 12;

int move(std::vector<std::vector<int>>& log) {
  // 맨 처음의 위치를 포함하여 N+1개 조사하면 종료
  if (log.size() == N + 1) {
    return 1;
  }

  int cnt = 0;
  // 전후 좌우로 이동
  std::vector<std::vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (const auto& d : directions) {
    // 탐색이 끝나지 않았으면 이동시킴
    std::vector<int> next_pos = {log.back()[0] + d[0], log.back()[1] + d[1]};
    // 로그에 다음 위치가 기록되어 있는지 확인하기
    bool check = false;
    for (const auto& p : log) {
      if (p[0] == next_pos[0] && p[1] == next_pos[1]) {
        check = true; // 있는 경우 플래그를 true로 변경
        break;
      }
    }
    if (!check) {
      log.push_back(next_pos);
      cnt += move(log);
      log.pop_back();
    }
  }
  return cnt;
}

int main() {
  std::vector<std::vector<int>> log = {{0, 0}};
  int result = move(log);
  std::cout << result << std::endl;

  return 0;
}