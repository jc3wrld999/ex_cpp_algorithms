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

void pattern(vector<int>& used, vector<int>& unused, int index) {
    if (unused.size() == 0) {
        solve(used, used, 0);
    }
    else {
        for (int i : unused) {
            if (index + 1 != i) {
                vector<int> temp = unused;
                temp.erase(find(temp.begin(), temp.end(), i));
                used.push_back(i);
                pattern(used, temp, index + 1);
                used.pop_back();
            }
        }
    }
}

int main() {
    vector<int> used;
    vector<int> unused(N);
    for (int i = 0; i < N; i++) {
        unused[i] = i + 1;
    }

    pattern(used, unused, 0);

    cout << max_value << endl;
    for (const auto& pair : max_list) {
        const vector<int>& key = pair.first;
        for (int i : key) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}