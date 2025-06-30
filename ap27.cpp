#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> zu(n);
  for (int i = 0; i < n; cin >> zu[i], i++);
  string result = zu[0];
  for (int i = 0; i < n - 1; i++) {
    string plus = zu[i + 1];
    for (int j = zu[i + 1].size(); j >= 1; j--) {
      string temp = zu[i + 1].substr(0, j);
      int s1 = zu[i].size();
      if (s1 >= temp.size() && zu[i].substr(s1 - j) == temp) {
        plus = zu[i + 1].substr(j);
        break;
      }
    }
    // if (f) {
    result += plus;
    // } else {
    //   result += zu[i + 1];
    // }
  }
  cout << result;
  return 0;
}