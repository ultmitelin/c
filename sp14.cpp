#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
using namespace std;
string s(int n) {
  if (n == 0) {
    return "0";
  }
  if (n == 1) {
    return "01";
  }
  if (n == 2) {
    return "0110";
  }
  string s1 = s(n - 1);
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == '0') {
      s1[i] = '1';
      continue;
    }
    s1[i] = '0';
  }
  return s(n - 1) + s1;
}
int main() {
  int n;
  cin >> n;
  cout << s(n);
}

// ds  version
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << "0\n";
    return 0;
  }
  string current = "0";
  current.reserve(1 << n);  // 预先分配最终所需的内存空间

  for (int i = 1; i <= n; ++i) {
    string new_part;
    new_part.reserve(current.size());  // 为新部分预分配空间
    for (char c : current) {
      new_part += c ^ 1;  // 利用ASCII特性翻转字符：'0'变'1'，'1'变'0'
    }
    current += new_part;  // 拼接原字符串和翻转后的部分
  }
  cout << current << endl;
  return 0;
}