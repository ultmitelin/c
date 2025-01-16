#include <iostream>
#include <string>
#include <vector>
using namespace std;
string zhuan(int a) {
  if (a == 0) return "0";
  if (a == 1) return "1";
  if (a == 2) return "4";
  if (a == 3) return "9";
}
int main() {
  long long a;
  while (cin >> a) {
    if (a == 0) cout << 0;
    // string s;
    // cin >> s;
    // cout << s.length();
    vector<long long> zu;
    while (a > 0) {
      zu.push_back(a % 4);
      a = a / 4;
    }
    string s;

    for (long long i = 0; i < zu.size(); i++) {
      s = zhuan(zu[i]) + s;
    }
    cout << s << endl;
  }
}