#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> magic_square = {1, 14, 14, 4, 11, 7, 6, 9, 8, 10, 10, 5, 13, 2, 3, 15};
    int sum_all = 0;
    for (int n : magic_square) {
        sum_all += n;
    }

    vector<int> ary(sum_all + 1, 0);
    ary[0] = 1;

    for (int n : magic_square) {
        for (int i = sum_all - n; i >= 0; i--) {
            ary[i + n] += ary[i];
        }
    }

    auto max_sum = max_element(ary.begin(), ary.end());
    int max_index = distance(ary.begin(), max_sum);
    cout << max_index << endl;

    return 0;
}