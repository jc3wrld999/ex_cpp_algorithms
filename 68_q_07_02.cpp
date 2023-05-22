#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
using namespace std;

int main() {
    int from_left = stoi(bitset<32>(19641010).to_string().substr(4, 8), nullptr, 2);
    int to_left = stoi(bitset<32>(20200724).to_string().substr(4, 8), nullptr, 2);

    for (int i = from_left; i <= to_left; ++i) {
        bitset<8> left(i);
        string left_str = left.to_string();
        string right_str(left_str.rbegin(), left_str.rend());
        for (int m = 0; m <= 1; ++m) {
            string value = "1001" + left_str + to_string(m) + right_str;
            try {
                bitset<32> date_bits(stoi(value, nullptr, 2));
                string date_str = date_bits.to_string();
                tm date_tm = {};
                istringstream date_ss(date_str);
                date_ss >> get_time(&date_tm, "%Y%m%d");
                if (!date_ss.fail()) {
                    cout << put_time(&date_tm, "%Y-%m-%d") << endl;
                }
            } catch (...) {
                // 변환 실패 시 무시
            }
        }
    }

    return 0;
}