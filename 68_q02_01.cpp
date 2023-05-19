#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string op[] = {"*", ""};

    for (int i = 1000; i < 10000; ++i) {
        std::string c = std::to_string(i);
        for (size_t j = 0; j < sizeof(op) / sizeof(op[0]); ++j) {
            for (size_t k = 0; k < sizeof(op) / sizeof(op[0]); ++k) {
                for (size_t l = 0; l < sizeof(op) / sizeof(op[0]); ++l) {
                    std::string val = c[3] + op[j] + c[2] + op[k] + c[1] + op[l] + c[0];

                    // 0으로 시작하는 숫자가 있는지 확인하고 있는 경우 제거합니다.
                    std::regex regex("0(\\d+)");
                    val = std::regex_replace(val, regex, "$1");

                    // 연산자를 하나는 넣는 경우
                    if (val.length() > 4) {
                        std::cout << val << std::endl;
                        if (i == std::stoi(val)) {
                            std::cout << val << " = " << i << std::endl;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 100; ++i) {
        std::cout << std::endl;
    }

    return 0;
}