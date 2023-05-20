#include <iostream>
#include <deque>

int cnt = 0;

void change(int target, std::deque<int> coins, int usable) {
    int coin = coins.front();
    coins.pop_front();

    if (coins.empty()) {
        if (target / coin <= usable) {
            cnt += 1;
        }
    } else {
        for (int i = 0; i <= target / coin; i++) {
            change(target - coin * i, coins, usable - i);
        }
    }
}

int main() {
    std::deque<int> coins = {500, 100, 50, 10};
    int usable = 15;

    change(1000, coins, usable);

    std::cout << cnt << std::endl;

    return 0;
}