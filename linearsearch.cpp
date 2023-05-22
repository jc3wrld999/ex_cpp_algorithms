#include <iostream>
#include <vector>
using namespace std;
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;  // 타겟을 찾은 인덱스 반환
        }
    }
    return -1;  // 타겟이 배열에 없을 경우 -1 반환
}

int main() {
    vector<int> arr = {2, 5, 1, 9, 7, 4};
    int target = 9;

    int index = linearSearch(arr, target);

    if (index != -1) {
        cout << "Target " << target << " found at index " << index << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}