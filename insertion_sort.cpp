#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> data = {6, 15, 4, 2, 8, 5, 11, 9, 7, 13};

    for (int i = 1; i < data.size(); i++) {
        int temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}