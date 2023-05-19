#include <iostream>
#include <vector>

int main() {
    std::vector<int> data = {6, 15, 4, 2, 8, 5, 11, 9, 7, 13};

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.size() - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }

    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}