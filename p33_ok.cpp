#include <iostream>
#include <vector>
using namespace std;
vector<int> shu;
void f(int x1, int x2) {
  if (shu[x1] == 0 || shu[x2] == 0) {
    if (shu[x1] == 0) {
      cout << "ERROR: T[" << x1 << "] is NULL";
      return;
    }
    cout << "ERROR: T[" << x2 << "] is NULL";
    return;
  }
  if (x1 == 1 || x2 == 1) {
    cout << 1 << ' ' << shu[1];
    return;
  }
  int M = max(x1, x2), m = min(x1, x2);
  if ((M - m) > 1) {
    // cout << "f" << M / 2 << ' ' << m << endl;
    f(M / 2, m);

  } else {
    if (M / 2 == m / 2) {
      cout << M / 2 << ' ' << shu[M / 2];
      return;
    } else {
      f(M / 2, m);
    }
  }
}
int main() {
  int n;
  cin >> n;
  shu.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> shu[i];
  }
  int x1, x2;
  cin >> x1 >> x2;
  f(x1, x2);
  return 0;
}