#include <iostream>
#include <vector>

int square = 6;
int count = 0;
std::vector<std::vector<std::vector<bool>>> is_used(square + 1, std::vector<std::vector<bool>>(square + 1, std::vector<bool>(2, false)));

void route(int x, int y, bool is_first_time) {
    if (x == square && y == square) {
        if (is_first_time) {
            route(0, 0, false);
        } else {
            count++;
        }
    }
    if (x < square) {
        if (!is_used[x][y][0]) {
            is_used[x][y][0] = true;
            route(x + 1, y, is_first_time);
            is_used[x][y][0] = false;
        }
    }
    if (y < square) {
        if (!is_used[x][y][1]) {
            is_used[x][y][1] = true;
            route(x, y + 1, is_first_time);
            is_used[x][y][1] = false;
        }
    }
}

int main() {
    route(0, 0, true);
    std::cout << count << std::endl;
    return 0;
}