#include <iostream>
#include <vector>

int main() {
    std::vector<int> data = {6, 15, 4, 2, 8, 5, 11, 9, 7, 13};

    for (int i = 1; i < data.size(); i++) {
        int temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}