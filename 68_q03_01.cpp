#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 100;
    vector<bool> cards(N, false);

    for (int i = 2; i <= N; i++) {
        int j = i - 1;
        while (j < N) {
            cards[j] = !cards[j];
            j += i;
        }
    }

    for (int i = 0; i < N; i++) {
        if (!cards[i]) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}