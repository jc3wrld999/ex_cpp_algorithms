#include <iostream>
#include <cmath>
#include <unordered_set>
#include <string>
using namespace std;
int main() {
  int i = 1;

  // 정수 부분을 포함하는 경우
  while (true) {
    i++;
    double root = sqrt(i);
    string str = to_string(root);
    str.erase(str.find('.'), 1);  // 소수점 제거
    unordered_set<char> unique_digits(str.begin(), str.begin() + 10);
    
    if (unique_digits.size() == 10) {
      break;
    }
  }
  
  cout << i << endl;

  // 소수 부분만 계산하는 경우
  i = 1;
  while (true) {
    i++;
    double root = sqrt(i);
    string str = to_string(root);
    str = str.substr(str.find('.') + 1, 10);  // 소수 부분 추출
    unordered_set<char> unique_digits(str.begin(), str.end());
    
    if (unique_digits.size() == 10) {
      break;
    }
  }
  
  cout << i << endl;

  return 0;
}