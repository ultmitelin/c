
#include <iostream>
#include <sstream>
using namespace std;
void decimalToHex(int decimalNumber) {
  stringstream ss;
  ss << hex;            // 设置为十六进制模式
  ss << decimalNumber;  // 输出十进制转十六进制的结果
  string hex = ss.str();
  cout << "十六进制表示: " << hex << endl;
}

int main() {
  int decimal = 42;
  decimalToHex(decimal);
  return 0;
}