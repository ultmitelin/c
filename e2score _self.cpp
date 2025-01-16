// 1207 2小时，1208又搞了一个多小时
// 关键在临界条件（必须想清楚，别急）要透彻理解题意，一次循环完了要记着变一下让离结束更近一点
// 一开始对奇数情况直接复制偶数情况改了一点点，（改后代码默认中间的1后面还有1）导致只有一个1的时候陷入死循环，要考虑全
//
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
long long qiu(int a) {
  if (a == 0) return 0;
  if (a == 1) return 1;
  int m = a, n = a, p = a;
  vector<int> er, er1;
  while (p) {
    er.push_back(p & 1);
    if ((p & 1) == 1) {
      er1.push_back(1);
    }
    p = p >> 1;
  }

  if (er1.size() % 2 == 0) {
    int wei = 0, x1 = 0, x2 = 0;
    for (int i = 0; wei < er1.size() / 2; i++) {
      x1 = x1 + (m & 1) * pow(2, i);
      if ((m & 1) == 1) {
        wei++;
      }
      // cout << i << "###" << x1 << endl;
      m = m >> 1;
    }
    int ci = 1, wei1 = 0;
    for (; wei1 <= (er1.size() / 2); ci++) {
      if ((n & 1) == 1) {
        wei1++;
      }
      n = (n >> 1);
    }
    x2 = (a >> (ci - 2));
    return a + qiu(x1) + qiu(x2);
  } else
  // 第一个x2和第二个x2求法不一样，第一个要找到中间下一个减一位，第二个要找中间的加一位
  // 想清楚，别急
  {
    // m = a;
    // n = a;
    if (er1.size() == 1 && a != 1) return (a + 1);
    int wei = 0, x1 = 0, x2 = 0;
    for (int i = 0; wei < er1.size() / 2; i++) {
      x1 = x1 + (m & 1) * pow(2, i);
      if ((m & 1) == 1) {
        wei++;
      }
      // cout << i << "###" << x1 << endl;
      m = m >> 1;
    }
    int ci = 1, wei1 = 0;
    for (; wei1 < (((er1.size() + 1) / 2)); ci++) {
      if ((n & 1) == 1) {
        wei1++;
      }
      // cout << ci << "??" << wei1 << endl;
      n = (n >> 1);
    }
    x2 = (a >> (ci - 1));
    return a + qiu(x1) + 1 + qiu(x2);
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a;
    cin >> a;
    cout << qiu(a) << endl;
  }
}