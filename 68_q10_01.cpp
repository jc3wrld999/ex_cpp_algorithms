#include <iostream>
#include <vector>
#include <numeric>

int sumMax(const std::vector<int>& roulette, int n) {
    int ans = 0;
    for (int i = 0; i < roulette.size(); i++) {
        int tmp = 0;
        if (i + n < roulette.size()) {
            // 배열의 양끝을 넘지 않는 경우
            tmp = std::accumulate(roulette.begin() + i, roulette.begin() + i + n + 1, 0);
        } else {
            // 배열의 양끝을 넘는 경우
            tmp = std::accumulate(roulette.begin() + i, roulette.end(), 0);
            tmp += std::accumulate(roulette.begin(), roulette.begin() + ((i + n) % roulette.size()) + 1, 0);
        }
        ans = std::max(ans, tmp);
    }
    return ans;
}

int main() {
    std::vector<int> european = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36,
                                 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9,
                                 22, 18, 29, 7, 28, 12, 35, 3, 26};
    std::vector<int> american = {0, 28, 9, 26, 30, 11, 7, 20, 32, 17, 5, 22, 34, 15,
                                 3, 24, 36, 13, 1, 0, 27, 10, 25, 29, 12, 8, 19, 31,
                                 18, 6, 21, 33, 16, 4, 23, 35, 14, 2};

    int cnt = 0;
    for (int i = 2; i <= 36; i++) {
        if (sumMax(european, i) < sumMax(american, i)) {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;

    return 0;
}