#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int boyerMooreSearch(const string& text, const string& pattern) {
    unordered_map<char, int> skip;
    for (int i = 0; i < pattern.length() - 1; i++) {
        skip[pattern[i]] = pattern.length() - i - 1;
    }

    int i = pattern.length() - 1;
    while (i < text.length()) {
        bool match = true;
        for (int j = 0; j < pattern.length(); j++) {
            if (text[i - j] != pattern[pattern.length() - 1 - j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i - pattern.length() + 1;
        }
        if (skip.count(text[i])) {
            i += skip[text[i]];
        } else {
            i += pattern.length();
        }
    }

    return -1;
}

int main() {
    string text = "DYITBOOK DYSHOP";
    string pattern = "DYS";

    int index = boyerMooreSearch(text, pattern);
    if (index != -1) {
        cout << "Pattern found at index " << index << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}