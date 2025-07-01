#include <string.h>

#include <iostream>
#include <map>
#include <set>
using namespace std;
void printmin() {
  string s;
  cin >> s;
  set<char> zu;
  map<char, int> c_digat;
  c_digat[s[0]] = 1;
  zu.emplace(s[0]);
  int i = 1;
  for (i = 1; i < s.length(); i++) {
    if (!zu.count(s[i])) {
      zu.emplace(s[i]);
      c_digat[s[i]] = 0;
      break;
    }
  }
  // cout << i << ' ';
  int j = 2;
  for (int ii = ++i; ii < s.length(); ii++) {
    if (!zu.count(s[ii])) {
      zu.emplace(s[ii]);
      c_digat[s[ii]] = j++;
    }
  }
  int jinzhi = zu.size();
  if (jinzhi == 1) {
    jinzhi = 2;
  }
  long long result = 0;
  for (int k = 0; k < s.length(); k++) {
    result = result * jinzhi + c_digat[s[k]];
  }
  cout << result << '\n';
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "case #" << i << ':' << '\n';
    printmin();
  }
}