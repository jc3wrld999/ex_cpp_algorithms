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
    int size = pow(6, 6);
    vector<int> all_dice(size, 0);

    for (int i = 0; i < size; ++i) {
        if (all_dice[i] == 0) {
            vector<int> check;
            while (all_dice[i] == 0 && find(check.begin(), check.end(), i) == check.end()) {
                check.push_back(i);
                i = next_dice(i);
            }

            try { // 루프했을 때 그 위치 이전은 루프 이외
                int index = find(check.begin(), check.end(), i) - check.begin();
                for (int j = 0; j < check.size(); ++j) {
                    if (j < index) {
                        all_dice[check[j]] = 1;
                    } else {
                        all_dice[check[j]] = 2;
                    }
                }
            } catch (const out_of_range& e) { // 이미 확인 완료된 값에 해당했을 때는 루프 이외
                for (const auto& j : check) {
                    all_dice[j] = 1;
                }
            }
        }
    }

    cout << size << endl;
    cout << count(all_dice.begin(), all_dice.end(), 1) << endl;

    return 0;
}