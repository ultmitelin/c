#include <iostream>
#include <string>
using namespace std;
int main() {
  string as, my;
  int m, n;
  cin >> as;
  my = as.substr(2, 10);
  // 从0开始数，2表示第三位，读取10位

  cout << my << endl;
}