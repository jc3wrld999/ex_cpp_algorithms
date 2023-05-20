#include <iostream>

void cutbar(int m, int n) {
    int count = 0;
    int current = 1; // 현재의 길이
    while (n > current) {
        current += (current < m) ? current : m;
        count += 1;
    }
    std::cout << count << std::endl;
}

int main() {
    cutbar(3, 20);
    cutbar(5, 100);

    return 0;
}