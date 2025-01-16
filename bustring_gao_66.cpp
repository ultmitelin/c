#include <cstring>
#include <iostream>
using namespace std;
int main() {
  char s[100], spot;
  cin >> s;
  int len = strlen(s);

  for (int i = 0; i < len; i++) {
    if (s[i] != '-')
      cout << s[i];
    else {
      if (i == 0 || s[i - 1] == '-' || i + 1 == len || s[i + 1] == '-') {
        cout << s[i];
      } else if (s[i - 1] == s[i + 1])
        i = i + 1;
      else

      {
        spot = s[i - 1] + 1;
        for (; spot < s[i + 1]; cout << spot, spot++);
      }
    }
  }
}