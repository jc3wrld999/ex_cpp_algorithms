#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& data) {
    for (int i = 0; i < data.size(); i++) {
        int minIndex = i;

        for (int j = i + 1; j < data.size(); j++) {
            if (data[minIndex] > data[j]) {
                minIndex = j;
            }
        }

        // Swap the current element with the minimum element
        swap(data[i], data[minIndex]);
    }
}

int main() {
    vector<int> data = {6, 15, 4, 2, 8, 5, 11, 9, 7, 13};

    selectionSort(data);

    cout << "Sorted data: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}