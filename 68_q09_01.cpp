#include <iostream>
#include <vector>
using namespace std;
int main() {
    int boy = 20;
    int girl = 10;
    boy++;
    girl++;

    vector<int> ary(boy * girl, 0);
    ary[0] = 1;

    for (int g = 0; g <= girl; g++) {
        for (int b = 0; b <= boy; b++) {
            if (b != g && boy - b != girl - g) {
                if (b > 0) {
                    ary[b + boy * g] += ary[b - 1 + boy * g];
                }
                if (g > 0) {
                    ary[b + boy * g] += ary[b + boy * (g - 1)];
                }
            }
        }
    }

    int result = ary[ary.size() - 2] + ary[ary.size() - boy - 1];
    cout << result << endl;

    return 0;
}