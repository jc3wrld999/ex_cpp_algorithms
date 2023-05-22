#include <iostream>

int N = 6;
int cnt = 0;

void search(int man_x, int man_y, int woman_x, int woman_y, int meet) {
    if (man_x <= N && man_y <= N && woman_x >= 0 && woman_y >= 0) {
        if (man_x == N && man_y == N && meet >= 2) {
            cnt++;
        }
        if (man_x == woman_x) {
            meet++;
        }
        if (man_y == woman_y) {
            meet++;
        }
        search(man_x + 1, man_y, woman_x - 1, woman_y, meet);
        search(man_x + 1, man_y, woman_x, woman_y - 1, meet);
        search(man_x, man_y + 1, woman_x - 1, woman_y, meet);
        search(man_x, man_y + 1, woman_x, woman_y - 1, meet);
    }
}

int main() {
    search(0, 0, N, N, 0);
    std::cout << cnt << std::endl;
    return 0;
}