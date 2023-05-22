#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N = 9;
int max_value = 0;
map<vector<int>, vector<int>> max_list;

void solve(vector<int>& cards, vector<int>& init, int depth) {
    if (cards[0] == 1) {
        if (max_value < depth) {
            max_value = depth;
            max_list.clear();
        }
        if (max_value == depth) {
            max_list[init] = cards;
        }
    }
    else {
        reverse(cards.begin(), cards.begin() + cards[0]);
        rotate(cards.begin(), cards.begin() + 1, cards.end());
        solve(cards, init, depth + 1);
    }
}

int main() {
    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cards[i] = i + 1;
    }

    do {
        vector<int> init = cards;
        solve(cards, init, 0);
    } while (next_permutation(cards.begin(), cards.end()));

    cout << max_value << endl;
    for (const auto& pair : max_list) {
        const vector<int>& key = pair.first;
        const vector<int>& value = pair.second;
        for (int i : key) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}