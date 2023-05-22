#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<int>> club = {
        {11000, 40}, {8000, 30}, {400, 24}, {800, 20}, {900, 14},
        {1800, 16}, {1000, 15}, {7000, 40}, {100, 10}, {300, 12}
    };
    int N = 150;

    vector<vector<int>> area(club.size() + 1, vector<int>(N + 1, 0));

    for (int i = club.size() - 1; i >= 0; --i) {
        for (int j = 0; j <= N; ++j) {
            if (j < club[i][1]) {
                area[i][j] = area[i + 1][j];
            } else {
                area[i][j] = max(area[i + 1][j], area[i + 1][j - club[i][1]] + club[i][0]);
            }
        }
    }

    cout << area[0][N] << endl;

    return 0;
}