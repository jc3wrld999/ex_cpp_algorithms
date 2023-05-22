#include <iostream>
#include <string>
using namespace std;
int main() {
    // 정수를 문자열로 변환 (to_string)
    int num = 42;
    string str_num = to_string(num);
    cout << "Number as string: " << str_num << endl;

    // 문자열을 정수로 변환 (stoi)
    string str = "12345";
    int parsed_num = stoi(str);
    cout << "Parsed number: " << parsed_num << endl;

    return 0;
}