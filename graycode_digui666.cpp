#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string graycode(int x) {
  if (x == 0) return "0";
  if (x == 1) return "1";
  return graycode(x >> 1) + (((x >> 1 & 1) ^ (x & 1)) ? "1" : "0");
}
int main() {
  int x;
  cin >> x;
  string a1;
  a1 = graycode(x);
  cout << a1;
}
// 要深刻理解本质，不会就去网上搜定义原理
// 别自己费大力瞎琢磨