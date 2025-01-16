/*#include <cstring>  // For memcpy
#include <iostream>

union Data {
  int i;
  float f;
  char str[20];
};

int main() {
  Data data;

  data.i = 42;
  std::cout << "data.i: " << data.i << std::endl;

  data.f = 3.14f;
  std::cout << "data.f: " << data.f << std::endl;

  strcpy(data.str, "Hello, World!");
  std::cout << "data.str: " << data.str << std::endl;

  // 注意：由于共用内存空间，写入一个成员会覆盖其他成员
  std::cout << "After writing to data.str:" << std::endl;
  std::cout << "data.i: " << data.i << std::endl;  // 不确定输出
  std::cout << "data.f: " << data.f << std::endl;  // 不确定输出

  return 0;
}*/

#include <iomanip>
#include <iostream>

using namespace std;
int main() {
  double value;
  cin >> value;
  union {
    double d;
    unsigned char bytes[8];  // double类型通常为8字节
  } data;
  data.d = value;

  // 根据系统字节序输出字节
  for (int i = 0; i < 8; ++i) {
    cout << hex << setfill('0') << setw(2) << (int)(data.bytes[i]) << " ";
  }
  // cout << endl << (double)data.d;
}