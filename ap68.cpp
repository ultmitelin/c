#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1;
  s2 = "";
  int n = s1.size();
  for (int i = n - 1; i >= 0; i--) {
    s2 += s1[i];
  }
  for (int i = (n / 2); i > 0; i--) {
    for (int j = 0; j < n - 2 * i; j++) {
      for (int k = 0; k < n - 2 * i - j; k++) {
        if (s1.compare(j, i, s2, k, i) == 0) {
          cout << i;
          return 0;
        }
      }
    }
  }
  cout << 0;
  return 0;
}