#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

unordered_map<string, int> memo;

int strike(vector<vector<int>>& board) {
    string key = "";
    for (const auto& b : board) {
        key += "[";
        for (int i : b) {
            key += to_string(i) + ",";
        }
        key += "]";
    }

    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int cnt = 0;
    for (const auto& b : board) {
        vector<vector<int>> next_board;
        for (const auto& i : board) {
            // 교집합이 없는 경우만 찾습니다.
            set<int> intersection;
            set_intersection(b.begin(), b.end(), i.begin(), i.end(), inserter(intersection, intersection.begin())); //  b와 i 범위의 교집합을 계산하여 intersection 컨테이너에 삽입
            if (intersection.empty()) {
                next_board.push_back(i);
            }
        }
        cnt += strike(next_board);
    }

    memo[key] = cnt;
    return cnt;
}

int main() {
    vector<vector<int>> board = {{1, 2}, {2, 3}, {7, 8}, {8, 9},{1, 4}, {3, 6}, {4, 7}, {6, 9}};

    // 1개씩 뚫는 방법을 추가
    for (int i = 1; i <= 9; i++) {
        board.push_back({i});
    }

    cout << strike(board) << endl;

    return 0;
}