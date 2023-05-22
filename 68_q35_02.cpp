#include <iostream>
#include <vector>

using namespace std;

// 다음 점을 취득한다
int next_dice(int dice) {
    int top = dice / (int)pow(6, 5);
    int left = dice % (int)pow(6, 5);
    return (left + 1) * (int)pow(6, top + 1) - (top + 1);
}

int main() {
    int count = 0;
    for (int i = 0; i < pow(6, 6); ++i) {
        vector<int> check;
        // 루프할 때까지 다음 주사위를 찾는다
        while (find(check.begin(), check.end(), i) == check.end()) {
            check.push_back(i);
            i = next_dice(i);
        }
        // 루프한 위치를 확인하고 루프 대상이 아니라면 카운트
        if (find(check.begin(), check.end(), i) != check.begin()) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}