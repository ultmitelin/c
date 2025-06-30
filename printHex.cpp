#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
// 用于以十六进制格式输出整数的函数
void printHex(int value) {
  union {
    int d;
    unsigned char bytes[4];
  } data;
  data.d = value;

  for (int i = 0; i < 4; ++i) {
    cout << hex << setfill('0') << setw(2) << static_cast<int>(data.bytes[i])
         << " ";
  }
  // cout << hex << value << " ";
}

// 用于以十六进制格式输出double的函数
void printHex(double value) {
  union {
    double d;
    unsigned char bytes[8];  // double类型通常为8字节
  } data;
  data.d = value;

  // 根据系统字节序输出字节
  for (int i = 0; i < 8; ++i) {
    cout << hex << setfill('0') << setw(2) << static_cast<int>(data.bytes[i])
         << " ";
  }
}

int main() {
  string line;
  // char *line;
  while (getline(cin, line)) {
    // 检查是否包含小数点，以确定是int还是double
    if (line.find('.') != string::npos) {
      // 包含小数点，视为double
      stringstream iss(line);
      double value;
      iss >> value;
      // // stoi(line, NULL, 10);
      cout << value << endl;
      printHex(value);
    } else {
      // 不包含小数点，视为int
      stringstream iss(line);
      int value;
      iss >> value;
      cout << value << endl;
      printHex(value);
    }
    cout << endl;  // 每个数值后换行
  }
  return 0;
}