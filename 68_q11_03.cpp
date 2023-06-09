#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> memo;

int fib(int n) {
    if (memo.count(n) > 0) {
        return memo[n];
    }

    if (n == 0 || n == 1) {
        memo[n] = 1;
    } else {
        memo[n] = fib(n - 1) + fib(n - 2);
    }

    return memo[n];
}

int main() {
    cout << fib(5) << endl;

    return 0;
}