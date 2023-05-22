#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N = 9;
int max_value = 0;
map<vector<int>, vector<int>> max_list;

void solve(vector<int>& cards, vector<int>& init, int depth) {
    for (int i = 1; i < cards.size(); i++) {
        if (i + 1 == cards[i]) {
            reverse(cards.begin(), cards.begin() + i + 1);
            solve(cards, init, depth + 1);
            reverse(cards.begin(), cards.begin() + i + 1);
        }
    }

    if (max_value < depth) {
        max_value = depth;
        max_list.clear();
    }
    if (max_value == depth) {
        max_list[cards] = init;
    }
}

int main() {
    vector<int> cards(N + 1);
    vector<int> init(N + 1);
    for (int i = 1; i <= N; i++) {
        cards[i] = i;
        init[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        swap(cards[1], cards[i]);
        swap(init[1], init[i]);
        solve(cards, init, 0);
        swap(cards[1], cards[i]);
        swap(init[1], init[i]);
    }

    cout << max_value << endl;
    for (const auto& pair : max_list) {
        const vector<int>& key = pair.first;
        const vector<int>& value = pair.second;
        for (int i : key) {
            cout << i << " ";
        }
        cout << ": ";
        for (int i : value) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}