#include <iostream>
#include <vector>
using namespace std;
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;  // 타겟을 찾은 인덱스 반환
        } else if (arr[mid] < target) {
            left = mid + 1;  // 오른쪽 절반 탐색
        } else {
            right = mid - 1;  // 왼쪽 절반 탐색
        }
    }

    return -1;  // 타겟이 배열에 없을 경우 -1 반환
}

int main() {
    vector<int> arr = {1, 2, 4, 5, 7, 9};
    int target = 4;

    int index = binarySearch(arr, target);

    if (index != -1) {
        cout << "Target " << target << " found at index " << index << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}