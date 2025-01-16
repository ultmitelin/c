#include <iostream>
using namespace std;
int main() {
  int a;

  string s;
  while (cin >> a) {
    cin >> s;
    long long b = 1;
    // 每次都要重新定义为1；
    int x = s.length();
    // 2/6也等于0；要想清楚，条件限定好；

    if (a > x && a % x == 0) {
      for (; a > 0; b = b * a, a = a - x);
    } else if (a > x && a % x != 0) {
      for (; a > x; b = b * a, a = a - x);
      b = b * a;
    } else {
      b = b * a;
    }
    cout << b << endl;
  }
}