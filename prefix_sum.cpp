#include <iostream>
#include <numeric> // include the <numeric> header for std::accumulate
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 원소들의 합계 구하기
    // T accumulate(InputIt first, InputIt last, T init);
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum: " << sum << std::endl; // 출력: Sum: 15

    // 원소들의 곱 구하기
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());
    std::cout << "Product: " << product << std::endl; // 출력: Product: 120

    return 0;
}