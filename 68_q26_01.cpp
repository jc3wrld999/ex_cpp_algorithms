#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

const int W = 10;
const int H = 10;

vector<int> parking;
vector<int> goal;
vector<int> start;

unordered_map<string, int> log;

void search(const vector<pair<vector<int>, int>>& prev, int depth) {
    vector<pair<vector<int>, int>> target;

    for (const auto& item : prev) {
        const vector<int>& parking = item.first;
        int pos = item.second;

        vector<int> directions = {-1, 1, W + 1, -W - 1};

        for (int d : directions) {
            int dd = pos + d;
            if (parking[dd] != 9) {
                vector<int> temp = parking;
                swap(temp[dd], temp[pos]);
                string tempStr = "";
                for (int val : temp) {
                    tempStr += to_string(val) + " ";
                }
                tempStr += to_string(dd);
                if (::log.find(tempStr) == ::log.end()) {
                    target.push_back({temp, dd});
                    ::log[tempStr] = depth + 1;
                }
            }
        }
    }

    vector<string> temp;
    for (const auto& item : target) {
        vector<int> tempVec = item.first;
        int dd = item.second;
        string tempStr = "";
        for (int val : tempVec) {
            tempStr += to_string(val) + " ";
        }
        tempStr += to_string(dd);
        temp.push_back(tempStr);
    }

    string goalStr = "";
    for (int val : goal) {
        goalStr += to_string(val) + " ";
    }
    goalStr += to_string((W + 1) * (H + 1) - 2);

    if (find(temp.begin(), temp.end(), goalStr) != temp.end()) {
        return;
    }

    if (!target.empty()) {
        search(target, depth + 1);
    }
}

int main() {
    vector<int> parking((W + 2) * (H + 2), 9);

    for (int i = 0; i < W; ++i) {
        parking[i + 1] = 1;
    }
    for (int i = 0; i < H; ++i) {
        parking[(W + 2) * (i + 1) + W + 1] = 1;
        parking[(W + 2) * (i + 1)] = 9;
    }
    for (int i = 0; i < W; ++i) {
        parking[(W + 2) * (H + 1) + i + 1] = 9;
    }

    goal = parking;
    goal[W + 1] = 2;

    start = parking;
    start[(W + 2) * (H + 1) - 3] = 2;

    vector<pair<vector<int>, int>> initialStates = {
        {start, (W + 2) * H - 2},
        {start, (W + 2) * (H + 1) - 3}
    };

    ::log[to_string((W + 2) * H - 2)] = 0;
    ::log[to_string((W + 2) * (H + 1) - 3)] = 0;

    search(initialStates, 0);

    string goalStr = "";
    for (int val : goal) {
        goalStr += to_string(val) + " ";
    }
    goalStr += to_string((W + 2) * (H + 1) - 2);

    cout << ::log[goalStr] << endl;

    return 0;
}