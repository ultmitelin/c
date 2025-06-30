#include <algorithm>
#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include <vector>
string trans(char x) {
  // if (x >= '0' && x <= '9') return x;
  // 这个思路也可以

  if (x == 'A' || x == 'B' || x == 'C' || x == '2') return "2";
  if (x == 'D' || x == 'E' || x == 'F' || x == '3') return "3";
  if (x == 'G' || x == 'H' || x == 'I' || x == '4') return "4";
  if (x == 'J' || x == 'K' || x == 'L' || x == '5') return "5";
  if (x == 'O' || x == 'N' || x == 'M' || x == '6') return "6";
  if (x == 'P' || x == 'Q' || x == 'R' || x == 'S' || x == '7') return "7";
  if (x == 'V' || x == 'U' || x == 'T' || x == '8') return "8";
  if (x == 'W' || x == 'X' || x == 'Y' || x == 'Z' || x == '9') return "9";
  if (x == '1') return "1";
  if (x == '0') return "0";
}

string zhuan(string a) {
  string x;
  for (int i = 0; i < a.size(); i++) {
    if (i == 0 && a[0] != '-') {
      x = trans(a[0]);
    } else {
      if (a[i] == '-') {
        continue;
      } else
        x = x + trans(a[i]);
    }

    if (x.size() == 4) x = x + '-';
  }
  return x;
}
int main() {
  int n;
  cin >> n;
  string a;
  getline(cin, a);
  vector<string> n1, n2;
  for (int i = 0; i < n; i++) {
    getline(cin, a);
    n1.push_back(zhuan(a));
    // string s = zhuan(a);
    // cout << s << endl;
  }
  sort(n1.begin(), n1.end());
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cout << n1[i];
      cnt++;
    } else {
      if (n1[i] == n1[i - 1]) {
        cnt++;
      } else {
        cout << ' ' << cnt << endl;
        cout << n1[i];
        cnt = 1;
      }
      if (i == n - 1) cout << ' ' << cnt;
    }
  }
}