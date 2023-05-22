#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums = {1, 2, 3, 5, 5, 6, 7, 8, 9, 10};

    vector<int> sliced = vector<int>(nums.begin() + 2, nums.begin() + 7);

    for (const auto& num : sliced) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}