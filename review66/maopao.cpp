#include <iostream>
using namespace std;
int main() {
  int zu[10] = {5, 6, 9, 2, 4, 65, 88, 0, 12, 13};
  // 进入循环前就定义好，并且给定初始值；否则可能运行错误；
  for (int i = 1; i < 10; i++) {
    int flag = 0;
    // 0到10-i次，具体去操作，明白数的规律
    for (int j = 0; j < 10 - i; j++) {
      if (zu[j] > zu[j + 1]) {
        swap(zu[j], zu[j + 1]);
        flag = 1;
      }
    }

    if (flag == 0) break;
  }
  cout << zu[9] << endl;
  for (int i = 0; i < 10; i++) {
    cout << zu[i] << ' ';
  }
  cout << endl;
  int ci = 0, zu1[10], a1 = 0, a2 = 0;
  for (int i = 0; i < 10; i++) {
    if (zu[i] % 2 != 0) {
      zu1[a1++] = zu[i];
      ci = ci + 1;
    }
  }
  a2 = ci;
  for (int i = 0; i < 10; i++) {
    if (zu[i] % 2 == 0)

    {
      zu1[a2++] = zu[i];
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << zu1[i] << ' ';
  }
}