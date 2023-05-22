#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

int main() {
    int N = 6;

    int max_cnt = 0;
    std::vector<int> temp(N - 1);
    for (int i = 1; i < N; ++i) {
        temp[i - 1] = i;
    }

    do {
        do {
            std::vector<std::pair<int, int>> path;
            int left = 0;
            int right = temp[0];
            for (int i = 0; i < N - 1; ++i) {
                path.push_back(std::make_pair(left, right));
                left = temp[i];
                path.push_back(std::make_pair(left, right));
                if (i + 1 < temp.size()) {
                    right = temp[i + 1];
                }
            }
            path.push_back(std::make_pair(left, 0));

            int cnt = 0;
            for (int i = 0; i < N * 2 - 1; ++i) {
                for (int j = i + 1; j < N * 2 - 1; ++j) {
                    if ((path[i].first - path[j].first) * (path[i].second - path[j].second) < 0) {
                        cnt++;
                    }
                }
            }

            max_cnt = std::max(max_cnt, cnt);
        } while (std::next_permutation(temp.begin(), temp.end()));
    } while (std::next_permutation(temp.begin(), temp.end()));

    std::cout << max_cnt << std::endl;

    return 0;
}