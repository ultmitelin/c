#include <cstring>
#include <iostream>
using namespace std;
int strend(const char *s, const char *t) {
  int a1 = strlen(s), a2 = strlen(t);
  int flag = 0;
  for (int i = a1 - a2; i < a1; i++) {
    if (s[i] == t[i - a1 + a2])
      continue;
    else
      flag = 1;
  }
  if (flag == 0)
    return 1;
  else
    return 0;
}
/*
Precondition:
   s points to a string,t points to a string.
Postcondition:
   returns 1 if the string t occurs at the end of the
string s, and zero otherwise
*/
int main() {
  // string s, t;

  // // //
  // cin >> s;
  // cin >> t;
  // cout << strend(s, t);

  // getline(cin, s);
  // getline(cin, t);
  // int j = 0;
  //
  char s[100], t[100];
  char a;
  int j = 0, k = 0;
  cout << "请输入第一个字符串：" << endl;
  cin.getline(s);

  cout << "请输入第二个字符串：" << endl;
  cin >> a;
  while (a != '\n') {
    t[k++] = a;
    cin >> a;
  }
  // cin >> a;
  // while (a != '\n') {
  //   s[j++] = a;
  //   cin >> a;
  // }
  // int k = 0;
  // cin >> a;
  // while (a != '\n') {
  //   t[k++] = a;
  //   cin >> a;
  // }
}