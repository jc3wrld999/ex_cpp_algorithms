#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <unordered_set>

using namespace std;

int main() {
    vector<string> ip;

    for (int i = 0; i < (1 << 16); i++) {
        // 16-bit number reversal
        string bit_sequence = bitset<16>(i).to_string();
        reverse(bit_sequence.begin(), bit_sequence.end());
        int j = stoi(bit_sequence, nullptr, 2);

        // Creating the dotted decimal string representation
        string s = to_string(i >> 8) + "." + to_string(i & 0xff) + "." + to_string(j >> 8) + "." + to_string(j & 0xff);

        // Checking if the string has exactly 11 unique characters (digits and dots only)
        if (s.size() == 15 && unordered_set<char>(s.begin(), s.end()).size() == 11) {
            ip.push_back(s);
        }
    }

    cout << ip.size() << endl;
    for (const string& address : ip) {
        cout << address << endl;
    }

    return 0;
}