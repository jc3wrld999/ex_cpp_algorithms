#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

vector<int> bit = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011,
                        0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011};

int main() {
    int min_value = 63; // Initialize with all bits flipped
    vector<int> seq = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    while (next_permutation(seq.begin(), seq.end())) {
        int sum_value = 0;
        for (int j = 0; j < seq.size() - 1; j++) {
            bitset<7> xor_result(bit[seq[j]] ^ bit[seq[j+1]]);
            sum_value += xor_result.count();
            if (min_value <= sum_value)
                break;
        }
        if (min_value > sum_value)
            min_value = sum_value;
    }

    cout << min_value << endl;

    return 0;
}