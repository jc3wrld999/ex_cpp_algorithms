#include <iostream>
#include <numeric> // include the <numeric> header for accumulate
#include <vector>
using namespace std;
int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    // 원소들의 합계 구하기
    // T accumulate(InputIt first, InputIt last, T init);
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum: " << sum << endl; // 출력: Sum: 15

    // 원소들의 곱 구하기
    int product = accumulate(numbers.begin(), numbers.end(), 1, multiplies<int>());
    cout << "Product: " << product << endl; // 출력: Product: 120

    return 0;
}