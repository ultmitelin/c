#include <cctype>
#include <iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool last = 0;
  int wei = 0;
  int wei1 = 0;
  for (auto c : s) {
    if (isdigit(c) && last) {
      wei1++;
    } else if (isdigit(c) && c != '0' && wei1 == 0) {
      wei1++;
      last = 1;
    } else {
      last = 0;
      if (wei1 != 0 && wei < wei1) {
        wei = wei1;
      }
      wei1 = 0;
    }
  }

  wei = (wei < wei1) ? wei1 : wei;

  cout << wei;
}

// ds——version
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int max_len = 0;
  int n = s.length();

  for (int i = 0; i < n;) {
    if (isdigit(s[i])) {
      int start = i;
      while (i < n && isdigit(s[i])) i++;
      int len = i - start;

      if (s[start] != '0') {
        max_len = max(max_len, len);
      } else {
        int k = start;
        while (k < i && s[k] == '0') k++;
        if (k == i) {
          max_len = max(max_len, 1);
        } else {
          max_len = max(max_len, i - k);
        }
      }
    } else {
      i++;
    }
  }
  cout << max_len << endl;
  return 0;
}