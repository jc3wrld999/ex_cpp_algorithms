#include <iostream>
#include <string>

int main() {
    int count = 0;     // '0'이 출현한 횟수
    int line = 1;      // 현재의 행 수
    int row = 1;       // 현재의 행의 값(비트열)

    while (count < 2014) {
        row ^= row << 1;   // 앞의 행에서 배타적 논리합으로 다음 행을 설정
        std::string row_str = std::bitset<32>(row).to_string(); // 비트열을 문자열로 변환

        // '0'의 수를 카운트
        count += std::count(row_str.begin(), row_str.end(), '0');
        line++;
    }

    std::cout << line << std::endl;   // 2,014개 카운트한 행을 출력

    return 0;
}