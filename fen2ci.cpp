#include <cmath>
#include <iostream>
using namespace std;
void f(int x) {
  for (int i = 14; i >= 0; i--) {
    if (i <= log(x) / log(2)) {
      if (i == 1)
        cout << "2";
      else if (i == 0)
        cout << "2(0)";
      else {
        cout << "2(";
        f(i);
        cout << ")";
      }
      x -= pow(2, i);
      if (x != 0) {
        cout << '+';
      }
    }
  };
}
int main() {
  int x;
  cin >> x;
  f(x);
}