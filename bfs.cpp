#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Position {
    int x;
    int y;
    int depth;
};

int main() {
    vector<vector<int>> maze = {
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

    queue<Position> positions;
    positions.push({1, 1, 0});

    while (!positions.empty()) {
        Position currPos = positions.front();
        positions.pop();

        int x = currPos.x;
        int y = currPos.y;
        int depth = currPos.depth;

        // 골에 도달하면 종료
        if (maze[x][y] == 1) {
            cout << depth << endl;
            break;
        }

        // 탐색 완료로 설정
        maze[x][y] = 2;

        // 상하좌우 탐색
        if (maze[x - 1][y] < 2) {
            positions.push({x - 1, y, depth + 1});
        }
        if (maze[x + 1][y] < 2) {
            positions.push({x + 1, y, depth + 1});
        }
        if (maze[x][y - 1] < 2) {
            positions.push({x, y - 1, depth + 1});
        }
        if (maze[x][y + 1] < 2) {
            positions.push({x, y + 1, depth + 1});
        }
    }

    return 0;
}