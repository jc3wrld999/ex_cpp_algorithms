#include <iostream>
using namespace std;

void cutbar(int m, int n) {
    int count = 0;
    int current = 1; // 현재의 길이
    while (n > current) {
        current += (current < m) ? current : m;
        count += 1;
    }
    cout << count << endl;
}

int main() {
    cutbar(3, 20);
    cutbar(5, 100);

    return 0;
}