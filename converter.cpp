#include <iostream>
#include <string>
using namespace std;
string conv(int number, int base) {
    string T = "0123456789ABCDEF";
    int i, j;
    string result;

    i = number;
    while (i != 0) {
        j = i % base;
        i = i / base;

        result = T[j] + result;
    }

    return result;
}