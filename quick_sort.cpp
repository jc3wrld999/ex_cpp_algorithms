#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int>& data) {
    if (data.size() <= 1) {
        return data;
    }

    int pivot = data[0];
    vector<int> left, right;

    for (int i = 1; i < data.size(); i++) {
        if (data[i] <= pivot) {
            left.push_back(data[i]);
        } else {
            right.push_back(data[i]);
        }
    }

    left = quickSort(left);
    right = quickSort(right);

    vector<int> sortedData;
    sortedData.reserve(left.size() + right.size() + 1);
    sortedData.insert(sortedData.end(), left.begin(), left.end());
    sortedData.push_back(pivot);
    sortedData.insert(sortedData.end(), right.begin(), right.end());

    return sortedData;
}

int main() {
    vector<int> data = {6, 15, 4, 2, 8, 5, 11, 9, 7, 13};

    vector<int> sortedData = quickSort(data);

    cout << "Sorted Data: ";
    for (int i = 0; i < sortedData.size(); i++) {
        cout << sortedData[i] << " ";
    }
    cout << endl;

    return 0;
}