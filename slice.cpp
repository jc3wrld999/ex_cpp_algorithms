#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 5, 5, 6, 7, 8, 9, 10};

    std::vector<int> sliced = std::vector<int>(nums.begin() + 2, nums.begin() + 7);

    for (const auto& num : sliced) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}