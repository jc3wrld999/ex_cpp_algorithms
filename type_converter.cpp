#include <iostream>
#include <string>

int main() {
    // 정수를 문자열로 변환 (std::to_string)
    int num = 42;
    std::string str_num = std::to_string(num);
    std::cout << "Number as string: " << str_num << std::endl;

    // 문자열을 정수로 변환 (std::stoi)
    std::string str = "12345";
    int parsed_num = std::stoi(str);
    std::cout << "Parsed number: " << parsed_num << std::endl;

    return 0;
}