#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>

int main() {
    int from_left = std::stoi(std::bitset<32>(19641010).to_string().substr(4, 8), nullptr, 2);
    int to_left = std::stoi(std::bitset<32>(20200724).to_string().substr(4, 8), nullptr, 2);

    for (int i = from_left; i <= to_left; ++i) {
        std::bitset<8> left(i);
        std::string left_str = left.to_string();
        std::string right_str(left_str.rbegin(), left_str.rend());
        for (int m = 0; m <= 1; ++m) {
            std::string value = "1001" + left_str + std::to_string(m) + right_str;
            try {
                std::bitset<32> date_bits(std::stoi(value, nullptr, 2));
                std::string date_str = date_bits.to_string();
                std::tm date_tm = {};
                std::istringstream date_ss(date_str);
                date_ss >> std::get_time(&date_tm, "%Y%m%d");
                if (!date_ss.fail()) {
                    std::cout << std::put_time(&date_tm, "%Y-%m-%d") << std::endl;
                }
            } catch (...) {
                // 변환 실패 시 무시
            }
        }
    }

    return 0;
}