#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int a;
  while (cin >> a) {
    for (int i = 1; i <= 2 * a + 1; i++) {
      if (i <= a + 1) {
        string s(a - i + 1, ' ');
        cout << s;
        string s1(2 * i - 1, '*');
        cout << s1 << endl;
      } else {
        string s(i - a - 1, ' ');
        cout << s;
        string s1(2 * (a + 1 - (i - a - 1)) - 1, '*');
        cout << s1 << endl;
      }
    }
  }
}
