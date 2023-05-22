#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 범위 내의 소수를 추출하는 함수
vector<int> prime_range(int a, int b) {
    vector<int> primes;
    for (int i = a; i < b; i++) {
        bool flag = true;
        int j = 2;
        while (j * j <= i) {
            if (i % j == 0) {
                flag = false;
                break;
            }
            j++;
        }
        if (flag) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    // 3자리의 소수 추출하기
    vector<int> primes = prime_range(100, 1000);

    // 맨 앞의 자리를 사용해서 해시 만들기
    unordered_map<int, vector<int>> prime_h;
    for (int prime : primes) {
        int key = prime / 100;
        prime_h[key].push_back(prime);
    }

    int cnt = 0;
    for (int r1 : primes) {
        for (int c1 : prime_h[r1 / 100]) {
            for (int c2 : prime_h[(r1 % 100) / 10]) {
                for (int c3 : prime_h[r1 % 10]) {
                    int r2 = ((c1 % 100) / 10) * 100 + ((c2 % 100) / 10) * 10 + ((c3 % 100) / 10);
                    int r3 = (c1 % 10) * 100 + (c2 % 10) * 10 + (c3 % 10);
                    if (binary_search(primes.begin(), primes.end(), r2) && binary_search(primes.begin(), primes.end(), r3)) {
                        unordered_set<int> unique_nums = { r1, r2, r3, c1, c2, c3 };
                        if (unique_nums.size() == 6) {
                            cnt++;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}