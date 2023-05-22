#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

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
      j += 1;
    }
    if (flag) {
      primes.push_back(i);
    }
  }
  return primes;
}

int main() {
  vector<int> primes = prime_range(100, 1000);

  unordered_map<int, vector<int>> prime_h;
  for (int prime : primes) {
    int key = prime / 100;
    prime_h[key].push_back(prime);
  }

  int cnt = 0;
  for (int r1 : primes) {
    for (int c1 : prime_h[r1 / 100]) {
      for (int r2 : prime_h[(c1 % 100) / 10]) {
        for (int c2 : prime_h[(r1 % 100) / 10]) {
          if ((r2 % 100) / 10 == (c2 % 100) / 10) {
            for (int r3 : prime_h[c1 % 10]) {
              if (c2 % 10 == (r3 % 100) / 10) {
                int c3 = (r1 % 10) * 100 + (r2 % 10) * 10 + (r3 % 10);
                if (binary_search(primes.begin(), primes.end(), c3)) {
                  if (unordered_set<int>{r1, r2, r3, c1, c2, c3}.size() == 6) {
                    cnt += 1;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  cout << cnt << endl;

  return 0;
}