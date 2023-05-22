#include <iostream>
#include <bitset>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // 반전할 마스크를 설정
    vector<int> mask(16);
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            mask[row * 4 + col] = (0b1111 << (row * 4)) | (0b1000100010001 << col);
        }
    }

    int max_value = 0;
    // 단계 수를 저장하는 배열
    vector<int> steps(1 << 16, -1);
    // 모두 백에서 시작
    steps[0] = 0;
    // 조사 대상의 큐
    queue<int> scanner;
    scanner.push(0);
    while (!scanner.empty()) {
        int check = scanner.front();
        scanner.pop();
        int next_steps = steps[check] + 1;
        for (int i = 0; i < 16; i++) {
            int n = check ^ mask[i];
            // 확인하지 않은 경우, 다시 조사한다
            if (steps[n] == -1) {
                steps[n] = next_steps;
                scanner.push(n);
                if (max_value < next_steps) {
                    max_value = next_steps;
                }
            }
        }
    }

    cout << max_value << endl; // 최대 단계 수
    cout << bitset<16>(steps[max_value]).to_string() << endl; // 초기 상태의 칸: 모두 흑
    return 0;
}