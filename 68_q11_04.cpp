#include <iostream>
#include <string>

int main() {
  int a = 1, b = 1;
  int count = 0;
  
  while (count < 11) {
    int c = a + b;
    int digit_sum = 0;
    
    std::string str_c = std::to_string(c);
    for (char digit : str_c) {
      digit_sum += (digit - '0');
    }
    
    if (c % digit_sum == 0) {
      std::cout << c << std::endl;
      count++;
    }
    
    a = b;
    b = c;
  }
  
  return 0;
}