#include <iostream>
#include <string>
using namespace std;

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

string conv(int number, int base) {
    string T = "0123456789ABCDEF";
    int i, j;
    string result;

    i = number;
    while (i != 0) {
        j = i % base;
        i = i / base;

        result = T[j] + result;
    }

    return result;
}

int main() {
    int num = 11;

    while (true) {
        // 진법에 따른 변수를 선언합니다.
        string num_10 = conv(num, 10);
        string num_8 = conv(num, 8);
        string num_2 = conv(num, 2);

        // 앞뒤가 같은지 확인합니다.
        if (isPalindrome(num_10) && isPalindrome(num_8) && isPalindrome(num_2)) {
            cout << num << endl;
            break;
        }

        // 홀수만 탐색하므로 2씩 늘립니다.
        num += 2;
    }

    return 0;
}