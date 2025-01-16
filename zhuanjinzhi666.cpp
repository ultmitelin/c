#include <cstring>
#include <iostream>
using namespace std;

void itob(int n, char s[100], int b) {
  // TODO: your function definition
  string biao = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string zhi;
  if (n == 0)
    zhi = "0";
  else if (n > 0) {
    while (n > 0) {
      int ciwei = n % b;
      zhi = biao[ciwei] + zhi;  // 加号前后顺序不能反，左边的在左边，右边的在右边
      n /= b;
      cout << zhi << ' ' << zhi.length() << endl;
    }

    for (int i = 0; i <= (int)zhi.length(); i++) {
      if (i == (int)zhi.length()) {
        s[i] = '\0';
      }
      s[i] = zhi[i];
    }
  } else {
    n = abs(n);
    s[0] = '-';
    while (n > 0) {
      int ciwei = n % b;
      zhi = biao[ciwei] + zhi;
      n /= b;
      cout << zhi << ' ' << zhi.length() << endl;
    }
    for (int i = 0; i <= (int)zhi.length(); i++) {
      if (i + 1 == (int)zhi.length()) {
        s[i + 1] = '\0';
      }
      s[i + 1] = zhi[i];
    }
  }
}
int main() {
  int n, b;
  char s[100];
  cin >> n >> b;
  itob(n, s, b);
  cout << s << endl;
  cout << s[4];
  return 0;
}