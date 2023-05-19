#include <iostream>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number = 17;
    if (is_prime(number)) {
        std::cout << number << " is prime." << std::endl;
    } else {
        std::cout << number << " is not prime." << std::endl;
    }

    return 0;
}