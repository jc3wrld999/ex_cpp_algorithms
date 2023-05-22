#include <iostream>

using namespace std;

int cutbar(int m, int n, int current) {
    if (current >= n) {
        return 0; // 잘라내기 완료
    } else if (current < m) {
        return 1 + cutbar(m, n, current * 2); // 다음은 현재의 2배가 된다
    } else {
        return 1 + cutbar(m, n, current + m); // 가위 수만큼 추가
    }
}

int main() {
    cout << cutbar(3, 20, 1) << endl;
    cout << cutbar(5, 100, 1) << endl;

    return 0;
}