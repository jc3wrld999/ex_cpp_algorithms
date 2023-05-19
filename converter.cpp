#include <iostream>
#include <string>

std::string conv(int number, int base) {
    std::string T = "0123456789ABCDEF";
    int i, j;
    std::string result;

    i = number;
    while (i != 0) {
        j = i % base;
        i = i / base;

        result = T[j] + result;
    }

    return result;
}