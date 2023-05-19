#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

// 대각선 확인
bool check(int x, const vector<int>& col) {
    // 배치 완료된 행을 반대 순서로 탐색
    for (int i = 0; i < col.size(); i++) {
        int row = col[i];
        if (x + i + 1 == row || x - i - 1 == row) {
            return false;
        }
    }
    return true;
}

void search(vector<int>& col) {
    if (col.size() == N) { // 전부 배치되면 출력
        for (int i = 0; i < N; i++) {
            cout << col[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (find(col.begin(), col.end(), i) == col.end()) { // 동일한 행은 사용하지 않음
            if (check(i, col)) {
                col.push_back(i);
                search(col);
                col.pop_back();
            }
        }
    }
}

int main() {
    vector<int> col;
    search(col);

    return 0;
}