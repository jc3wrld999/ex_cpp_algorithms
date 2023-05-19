#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int>& left, std::vector<int>& right) {
    std::vector<int> result;
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

std::vector<int> mergeSort(std::vector<int>& data) {
    if (data.size() <= 1) {
        return data;
    }

    int mid = data.size() / 2;

    std::vector<int> left(data.begin(), data.begin() + mid);
    std::vector<int> right(data.begin() + mid, data.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    std::vector<int> data = {6, 15, 4, 2, 8, 5, 11, 9, 7, 13};

    std::vector<int> sortedData = mergeSort(data);

    for (int i = 0; i < sortedData.size(); i++) {
        std::cout << sortedData[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}