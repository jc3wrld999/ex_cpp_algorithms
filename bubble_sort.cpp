#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> data = {6, 15, 4, 2, 8, 5, 11, 9, 7, 13};

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.size() - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }

    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}