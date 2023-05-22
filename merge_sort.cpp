#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

vector<int> mergeSort(vector<int>& data) {
    if (data.size() <= 1) {
        return data;
    }

    int mid = data.size() / 2;

    vector<int> left(data.begin(), data.begin() + mid);
    vector<int> right(data.begin() + mid, data.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    vector<int> data = {6, 15, 4, 2, 8, 5, 11, 9, 7, 13};

    vector<int> sortedData = mergeSort(data);

    for (int i = 0; i < sortedData.size(); i++) {
        cout << sortedData[i] << " ";
    }
    cout << endl;

    return 0;
}