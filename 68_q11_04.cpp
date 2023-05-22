#include <iostream>
#include <string>
using namespace std;
int main() {
  int a = 1, b = 1;
  int count = 0;
  
  while (count < 11) {
    int c = a + b;
    int digit_sum = 0;
    
    string str_c = to_string(c);
    for (char digit : str_c) {
      digit_sum += (digit - '0');
    }
    
    if (c % digit_sum == 0) {
      cout << c << endl;
      count++;
    }
    
    a = b;
    b = c;
  }
  
  return 0;
}