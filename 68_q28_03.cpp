#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

unordered_map<string, int> memo;

int search(vector<vector<int>>& club, int remain) {
    string key = to_string(remain) + "-";
    for (const auto& c : club) {
        key += to_string(c[0]) + "-" + to_string(c[1]) + "-";
    }

    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int max_value = 0;
    for (auto it = club.begin(); it != club.end(); ++it) {
        if (remain - (*it)[1] >= 0) {
            vector<vector<int>> next_club = club;
            next_club.erase(it);
            max_value = max((*it)[0] + search(next_club, remain - (*it)[1]), max_value);
        }
    }

    memo[key] = max_value;
    return max_value;
}

int main() {
    vector<vector<int>> club = {
        {11000, 40}, {8000, 30}, {400, 24}, {800, 20}, {900, 14},
        {1800, 16}, {1000, 15}, {7000, 40}, {100, 10}, {300, 12}
    };
    int N = 150;

    int result = search(club, N);
    cout << result << endl;

    return 0;
}