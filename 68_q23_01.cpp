#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<pair<int, int>, int> memo;

int game(int coin, int depth) {
    pair<int, int> key = {coin, depth};
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    if (coin == 0) {
        return 0;
    }
    if (depth == 0) {
        return 1;
    }
  
    int win = game(coin + 1, depth - 1);  // 이길 때
    int lose = game(coin - 1, depth - 1); // 질 때
  
    memo[key] = win + lose;
    return memo[key];
}

int main() {
    cout << game(10, 24) << endl;

    return 0;
}