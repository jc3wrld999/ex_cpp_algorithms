#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

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


string run_length_encoding(const string& st) {
    string res;
    int n = st.length();
    int i = 0;
    while (i < n - 1) {
        int count = 1;
        while (i < n - 1 && st[i] == st[i + 1]) {
            count++;
            i++;
        }
        res += st[i] + to_string(count);
        i++;
    }
    return res;
}

string run_length_decoding(const string& compressed_seq) {
    string res;
    char current_letter = '\0';
    for (char c : compressed_seq) {
        if (isdigit(c)) {
            if (current_letter != '\0') {
                int count = c - '0';
                res.append(count, current_letter);
            }
        }
        else {
            current_letter = c;
        }
    }
    return res;
}

bool starts_with(const string& str, const string& prefix) {
    return str.size() >= prefix.size() && str.substr(0, prefix.size()) == prefix;
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

    string encoded = run_length_encoding("wwwwaaadexxxxxxywww");
    cout << encoded << endl;

    string decoded = run_length_decoding("w4a3d1e1x6y1w3");
    cout << decoded << endl;

    return 0;
}