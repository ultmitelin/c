#include <iostream>
using namespace std;
int main() {
  unsigned int highestDigit1 = 123456789012345678;
  while (highestDigit1 / 10 >= 1) {  // 取余操作，直到余数不是0
    highestDigit1 /= 10;
  }
  cout << highestDigit1;
}