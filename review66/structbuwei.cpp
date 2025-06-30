#include <iostream>
using namespace std;
struct a1 {
  char b;
  int a;

  short c;
};
// 补位原则
// a1为12   a2为8   初始开始每隔内存最大的大小是一个
// 若和下一个拼起来超过最大的，就分别补位
struct a2 {
  int a;
  char b;
  short c;
};
int main() { cout << sizeof(a1) << endl << sizeof(a2); }