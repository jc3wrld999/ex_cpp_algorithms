#include <iostream>
#include <vector>
#include <numeric>

int sum_max(const std::vector<int>& roulette, int n) {
    int ans = std::accumulate(roulette.begin(), roulette.begin() + n, 0);
    int tmp = ans;
    for (int i = 0; i < roulette.size(); i++) {
        tmp += roulette[(i + n) % roulette.size()];
        tmp -= roulette[i];
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
        if (sum_max(european, i) < sum_max(american, i)) {
            cnt++;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}