#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int count = 0;
    std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    do {
        int r = digits[0], e = digits[1], a = digits[2], d = digits[3];
        int w = digits[4], i = digits[5], t = digits[6], l = digits[7];
        int k = digits[8], s = digits[9];
        
        if (r == 0 || w == 0 || t == 0 || s == 0)
            continue;
        
        int read = r * 1000 + e * 100 + a * 10 + d;
        int write = w * 10000 + r * 1000 + i * 100 + t * 10 + e;
        int talk = t * 1000 + a * 100 + l * 10 + k;
        int skill = s * 10000 + k * 1000 + i * 100 + l * 10 + l;
        
        if (read + write + talk == skill) {
            count++;
            std::cout << read << " + " << write << " + " << talk << " = " << skill << std::endl;
        }
    } while (std::next_permutation(digits.begin(), digits.end()));
    
    std::cout << count << std::endl;
    
    return 0;
}