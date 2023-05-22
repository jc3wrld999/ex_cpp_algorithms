#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 고정적인 형태의 진법 변환 함수
string conv(int number, int base) {
    string T = "0123456789ABCDEF";
    int i, j;
    i = number / base;
    j = number % base;
    if (i == 0) {
        return string(1, T[j]);
    } else {
        return conv(i, base) + T[j];
    }
}

// 다음 눈을 취득한다
string next_dice(string dice) {
    int right = stoi(dice.substr(0, dice[0] - '0'));
    string right_str = to_string(right);
    for (char& c : right_str) {
        switch (c) {
            case '1':
                c = '6';
                break;
            case '2':
                c = '5';
                break;
            case '3':
                c = '4';
                break;
            case '4':
                c = '3';
                break;
            case '5':
                c = '2';
                break;
            case '6':
                c = '1';
                break;
        }
    }
    dice += right_str;
    return dice;
}

int main() {
    int count = 0;
    unordered_map<string, int> check;
    for (int i = 0; i < pow(6, 6); ++i) {
        // 6진수로 표현하여 '111111'을 더함으로써 1~6이 된다
        string dice = conv(i, 6);
        dice = to_string(stoi(dice) + 111111);
        check.clear();
        int j = 0;
        // 루프할 때까지 다음의 주사위를 찾는다
        while (check.find(dice) == check.end()) {
            check[dice] = j;
            dice = next_dice(dice);
            j++;
        }
        // 루프한 위치를 확인하고 루프 대상이 아니라면 카운트
        if (check.find(dice) != check.end() && check[dice] > 0) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}