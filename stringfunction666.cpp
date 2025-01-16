// 有写好的函数就用写好的，别自己傻乎乎循环遍历替换，你那是事倍功半费无用功
#include <iostream>
using namespace std;
int main() {
  string s1;
  cin >> s1;
  s1.erase(2, 3);
  cout << s1.find("123");
  s1.erase(1);
  cout << endl << s1;
}

using namespace std;
int main() {
  string s, s1 = "0";
  int a;
  cin >> s >> a;
  cout << s.length() << ' ';
  int wei = a;
  if (a > s.length()) wei = a % s.length();
  // char ab[100] = "0";
  string ss1(s, s.length() - wei, wei);
  string ss2(s, 0, s.length() - wei);
  // for (int i = 0; i < wei; i++) {
  //   ab[i] = s[s.length() - wei + i];
  // }
  // for (int i = 0; i < s.length() - wei; s1[i] = s[i], i++);
  // for (int i = s.length() - 1; i >= s.length() - 1 - wei; i--) {
  //   s[i] = s[i - wei];
  // }
  s.replace(0, wei - 1, ss1);
  s.replace(wei, s.length(), ss2);
  // for (int i = 0; i < wei; i++) {
  //   s[i] = ss1[i];
  // }
  // for (int i = wei; i < s.length(); i++) {
  //   s[i] = ss2[i - wei];
  // }
  // long long x = stoll(s, NULL, 10);
  while (s[0] == '0' && s.length() != 1) s.erase(0, 1);
  // cout << s1 << endl;
  cout << s;
}