#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 4;

    // 초기 카드 상태를 설정합니다.
    vector<vector<int>> cards = {vector<int>(n * 2)};
    for (int i = 0; i < n * 2; i++) {
        cards[0][i] = i + 1;
    }
    vector<int> answer(n * 2);
    for (int i = 0; i < n * 2; i++) {
        answer[i] = n * 2 - i;
    }

    bool flag = true;
    int depth = 1;
    while (flag) {
        // 탐색 결과를 저장할 벡터를 초기화합니다.
        vector<vector<int>> result;
        for (const vector<int>& c : cards) {
            for (int i = 1; i <= n; i++) {
                // 카드의 일부를 회전시킵니다.
                vector<int> temp(n * 2);
                rotate_copy(c.begin() + i, c.begin() + i + n, c.end(), temp.begin());
                rotate_copy(c.begin(), c.begin() + i, c.begin() + i + n, temp.begin() + n);
                // 회전 후 상태를 확인하여 목표 상태와 일치하는지 확인합니다.
                if (temp == answer) {
                    flag = false;
                }
                result.push_back(temp);
            }
        }
        // 다음 탐색을 위해 결과를 업데이트합니다.
        cards = result;
        depth++;
    }

    cout << depth << endl;

    return 0;
}