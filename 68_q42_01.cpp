#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n = 5;

    // 순방향 탐색 초기 카드 상태를 설정합니다.
    vector<vector<int>> fw = {vector<int>(n * 2)};
    for (int i = 0; i < n * 2; i++) {
        fw[0][i] = i + 1;
    }

    // 역방향 탐색 초기 카드 상태를 설정합니다.
    vector<vector<int>> bw = {vector<int>(n * 2)};
    for (int i = 0; i < n * 2; i++) {
        bw[0][i] = n * 2 - i;
    }

    int depth = 1;
    while (true) {
        // 순방향 탐색
        vector<vector<int>> fw_temp;
        for (const vector<int>& c : fw) {
            for (int i = 1; i <= n; i++) {
                vector<int> temp(n * 2);
                rotate_copy(c.begin() + i, c.begin() + i + n, c.end(), temp.begin());
                rotate_copy(c.begin(), c.begin() + i, c.begin() + i + n, temp.begin() + n);
                fw_temp.push_back(temp);
            }
        }
        fw = fw_temp;

        // 순방향 탐색 결과와 역방향 탐색 결과 중 중복된 상태를 확인합니다.
        unordered_set<vector<int>> fw_set(fw.begin(), fw.end());
        unordered_set<vector<int>> intersection;
        for (const vector<int>& c : bw) {
            if (fw_set.find(c) != fw_set.end()) {
                intersection.insert(c);
            }
        }
        if (!intersection.empty()) {
            break;
        }

        depth++;

        // 역방향 탐색
        vector<vector<int>> bw_temp;
        for (const vector<int>& c : bw) {
            for (int i = 1; i <= n; i++) {
                vector<int> temp(n * 2);
                rotate_copy(c.begin() + n, c.begin() + i + n, c.begin() + n + n, temp.begin());
                rotate_copy(c.begin(), c.begin() + i, c.begin() + i + n, temp.begin() + n);
                bw_temp.push_back(temp);
            }
        }
        bw = bw_temp;

        // 순방향 탐색 결과와 역방향 탐색 결과 중 중복된 상태를 확인합니다.
        unordered_set<vector<int>> bw_set(bw.begin(), bw.end());
        intersection.clear();
        for (const vector<int>& c : fw) {
            if (bw_set.find(c) != bw_set.end()) {
                intersection.insert(c);
            }
        }
        if (!intersection.empty()) {
            break;
        }

        depth++;
    }

    cout << depth << endl;

    return 0;
}