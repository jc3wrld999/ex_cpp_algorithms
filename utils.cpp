#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>


using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int ex_accumulate() { // T accumulate(InputIt first, InputIt last, T init);
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 원소들의 합계 구하기
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    // 원소들의 곱 구하기
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());

    return sum;
}

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void arrayHandler() {
    // input to array
    int rows, columns;
    cout << "행 수를 입력하세요: ";
    cin >> rows;
    cout << "열 수를 입력하세요: ";
    cin >> columns;

    vector<vector<int>> matrix(rows, vector<int>(columns));

    cout << "행렬 요소를 입력하세요:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
        }
    }

    // slice
    vector<int> nums = {1, 2, 3, 5, 5, 6, 7, 8, 9, 10};
    vector<int> sliced = vector<int>(nums.begin() + 2, nums.begin() + 7);

    // reverse (#include algorithms)
    reverse(nums.begin(), nums.end());

}

void ex_ref() {
    // * 연산자는 포인터 변수를 역참조하여 해당 메모리 주소에 저장된 값을 가져옴
    //  포인터 변수를 역참조할 때 사용되며, 포인터 변수가 유효한 메모리를 가리킬 때 사용
    int value = 42;
    int* ptr = &value; // 포인터 변수 ptr은 value의 메모리 주소를 가리킴

    int dereferencedValue = *ptr; // 포인터 ptr을 역참조하여 value의 값을 얻음


    // & 연산자는 변수에 대한 참조를 생성, 참조 변수는 항상 다른 변수를 참조
    // 값을 카피하지 않을 때 사용하는 듯

    int value = 42;
    int& ref = value; // 참조 변수 ref는 value를 참조

    ref = 100; // value의 값을 변경

    int newValue = 200;
    ref = newValue; // value의 값을 newValue로 변경
}