#include <iostream>
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
  for (int i = 0; i < wei; i++) {
    s[i] = ss1[i];
  }
  for (int i = wei; i < s.length(); i++) {
    s[i] = ss2[i - wei];
  }
  long long x = stoll(s, NULL, 10);
  // cout << s1 << endl;
  cout << x;
}