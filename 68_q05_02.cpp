#include <iostream>
#include <deque>
using namespace std;

int cnt = 0;

void change(int target, deque<int>& coins, int usable) {
    int coin = coins.front();
    coins.pop_front();

    if (coins.empty()) {
        if (target / coin <= usable) {
            cnt++;
        }
    } else {
        for (int i = 0; i <= target / coin; i++) {
            change(target - coin * i, coins, usable - i);
        }
    }

    coins.push_front(coin);
}

int main() {
    deque<int> coins = {500, 100, 50, 10};
    change(1000, coins, 15);
    cout << cnt << endl;

    return 0;
}