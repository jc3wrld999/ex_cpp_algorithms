#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

vector<int> bit = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011,
                        0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011};

vector<vector<int>> flip(10, vector<int>(10));

int min_value = 63;

void search(vector<bool>& is_used, int sum_value, int prev) {
    if (count(is_used.begin(), is_used.end(), false) == 0) {
        min_value = sum_value;
    } else {
        for (int i = 0; i < 10; i++) {
            if (!is_used[i]) {
                is_used[i] = true;
                int next_sum = 0;
                if (prev >= 0) {
                    next_sum = sum_value + flip[prev][i];
                }
                if (min_value > next_sum) {
                    search(is_used, next_sum, i);
                }
                is_used[i] = false;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            bitset<7> xor_result(bit[i] ^ bit[j]);
            flip[i][j] = xor_result.count();
        }
    }

    vector<bool> is_used(10, false);
    search(is_used, 0, -1);
    cout << min_value << endl;

    return 0;
}