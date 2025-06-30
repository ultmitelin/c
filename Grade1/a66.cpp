#include <iostream>
using namespace std;

int main() {
  for (int i = 1; i <= 9; i++) {    // 外层循环控制行数
    for (int j = 1; j <= i; j++) {  // 内层循环控制每行的列数
      cout << j << " * " << i << " = " << i * j << " ";  // 输出乘法表的内容
    }
    cout << endl;  // 每输出一行后换行
  }
  return 0;
}