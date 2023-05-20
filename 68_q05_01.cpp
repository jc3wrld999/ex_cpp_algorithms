#include <iostream>

int main() {
    int cnt = 0;

    for (int coin_500 = 0; coin_500 <= 2; coin_500++) {
        for (int coin_100 = 0; coin_100 <= 10; coin_100++) {
            for (int coin_50 = 0; coin_50 <= 15; coin_50++) {
                for (int coin_10 = 0; coin_10 <= 15; coin_10++) {
                    if (coin_500 + coin_100 + coin_50 + coin_10 <= 15) {
                        if (coin_500 * 500 + coin_100 * 100 + coin_50 * 50 + coin_10 * 10 == 1000) {
                            cnt += 1;
                        }
                    }
                }
            }
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}