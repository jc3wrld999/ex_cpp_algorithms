#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> bit = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011,
                        0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011};

int main() {
    int flip[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            bitset<7> xor_result(bit[i] ^ bit[j]); // bit[i]와 bit[j]의 배타적 논리합(xor) 결과를 7비트로 표현
            flip[i][j] = xor_result.count();
        }
    }

    int min_value = 63;
    vector<int> seq = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    while (next_permutation(seq.begin(), seq.end())) {
        int sum_value = 0;
        for (int j = 0; j < seq.size() - 1; j++) {
            sum_value += flip[seq[j]][seq[j+1]];
            if (min_value <= sum_value)
                break;
        }
        if (sum_value < min_value)
            min_value = sum_value;
    }

    cout << min_value << endl;

    return 0;
}