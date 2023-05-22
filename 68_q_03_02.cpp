#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i <= 100; i++) {
        bool flag = false;
        for (int j = 1; j <= 100; j++) {
            if (i % j == 0) {
                flag = !flag;
            }
        }
        if (flag) {
            cout << i << endl;
        }
    }

    return 0;
}