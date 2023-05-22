#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

int main() {
    const int N = 8;
    const int start = (1 << N) - 1;
    const int mask = (1 << (N * 2)) - 1;

    const int goal1 = ((1 << (N * 2)) - 1) / 3;
    const int goal2 = ((1 << (N * 2)) - 1) * 2 / 3;

    int count = N * 2;
    for (int i = 0; i < (1 << (N * 2)); i++) {
    int turn = i ^ (i << 1) ^ (i << 2);
    turn = (turn ^ (turn >> (N * 2))) & mask;

    if ((start ^ turn) == goal1 || (start ^ turn) == goal2) {
        // "count" 변수와 "std::bitset<N * 2>(i).count()"의 값을 비교하여 더 작은 값을 "count" 변수에 할당
        // bitset<N * 2>(i)"는 "i"를 N * 2 비트로 표현한 이진 수
        count = min(count, static_cast<int>(bitset<N * 2>(i).count())); 
        cout << bitset<N * 2>(i) << endl;
    }
    }

    cout << count << endl;

    return 0;
}