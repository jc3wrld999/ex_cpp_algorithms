#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<int> n;
    for (int i = 1; i <= 50; ++i) {
        if (i % 2 > 0 || i % 5 > 0) {
            n.push_back(i);
        }
    }

    vector<int> answer;
    int k = 1;
    while (!n.empty()) {
        int x = k * 7;
        if (to_string(x).find('0') != string::npos) {
            for (auto it = n.begin(); it != n.end(); ++it) {
                if (x % (*it) == 0) {
                    if (to_string(x) == string(to_string(x).rbegin(), to_string(x).rend())) {
                        answer.push_back(*it);
                    }
                    n.erase(it);
                    break;
                }
            }
        }
        ++k;
    }

    sort(answer.begin(), answer.end());

    for (int i : answer) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}