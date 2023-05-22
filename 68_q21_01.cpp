#include <iostream>
#include <vector>

using namespace std;

int main() {
    int count = 0;     // '0'이 출현한 횟수
    int line = 1;      // 현재의 행 수
    vector<int> row = {1};     // 현재의 행의 값

    while (count < 2014) {
        vector<int> next_row = {1};
        // 앞의 행에서 배타적 논리합으로 다음 행을 설정
        for (int i = 0; i < row.size() - 1; i++) {
            int cell = row[i] ^ row[i + 1];
            next_row.push_back(cell);
            if (cell == 0) {     // '0'인 경우에 카운트
                count++;
            }
        }
        next_row.push_back(1);
        line++;           // 행 수를 늘려 다음의 행으로
        row = next_row;
    }

    cout << line << endl;   // 2,014개 카운트한 행을 출력

    return 0;
}