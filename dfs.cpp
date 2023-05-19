#include <iostream>
#include <vector>

std::vector<std::vector<int>> maze = {
    {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
    {9, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 9},
    {9, 0, 9, 0, 0, 0, 9, 9, 0, 9, 9, 9},
    {9, 0, 9, 9, 0, 9, 0, 0, 0, 9, 0, 9},
    {9, 0, 0, 0, 9, 0, 0, 9, 9, 0, 9, 9},
    {9, 9, 9, 0, 0, 9, 0, 9, 0, 0, 0, 9},
    {9, 0, 0, 0, 9, 0, 9, 0, 0, 9, 1, 9},
    {9, 0, 9, 0, 0, 0, 0, 9, 0, 0, 9, 9},
    {9, 0, 0, 9, 0, 9, 0, 0, 9, 0, 0, 9},
    {9, 0, 9, 0, 9, 0, 9, 0, 0, 9, 0, 9},
    {9, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 9},
    {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
};

void search(int x, int y, int depth) {
    // 골에 도달하면 종료
    if (maze[x][y] == 1) {
        std::cout << depth << std::endl;
        exit(0);
    }

    // 탐색 완료로 설정
    maze[x][y] = 2;

    // 상하좌우 탐색
    if (maze[x - 1][y] < 2) {
        search(x - 1, y, depth + 1);
    }
    if (maze[x + 1][y] < 2) {
        search(x + 1, y, depth + 1);
    }
    if (maze[x][y - 1] < 2) {
        search(x, y - 1, depth + 1);
    }
    if (maze[x][y + 1] < 2) {
        search(x, y + 1, depth + 1);
    }

    // 탐색 전으로 되돌리기
    maze[x][y] = 0;
}

int main() {
    // 시작 위치에서 출발
    search(1, 1, 0);
    return 0;
}