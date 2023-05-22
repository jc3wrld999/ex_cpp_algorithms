#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
  vector<int> primes = {2, 3, 5, 7, 11, 13};
  int min_value = primes.back() * primes.back();  // 최대로 가장 큰 것의 제곱
  vector<int> min_friend;

  // Generate permutations of the prime numbers
  while (next_permutation(primes.begin(), primes.end())) {
    vector<int> friends;
    for (size_t i = 0; i < primes.size() - 1; ++i) {
      friends.push_back(primes[i] * primes[i + 1]);
    }
    friends.push_back(primes[0] * primes[0]);
    friends.push_back(primes.back() * primes.back());

    if (min_value > *max_element(friends.begin(), friends.end())) {
      min_value = *max_element(friends.begin(), friends.end());
      min_friend = friends;
    }
  }

  cout << min_value << endl;

  sort(min_friend.begin(), min_friend.end());
  for (const auto& friend_value : min_friend) {
    cout << friend_value << " ";
  }
  cout << endl;

  return 0;
}