#include <iostream>
#include <vector>
using namespace std;
vector<int> p;
int findx(int x) {
  if (x != p[x]) {
    return x = findx(p[x]);
  }
  return x;
}
void unionxx(int x1, int x2) {
  int rootx1 = findx(x1);
  int rootx2 = findx(x2);
  if (rootx1 == rootx2) {
    return;
  }
  p[rootx2] = rootx1;
  return;
}

int main() {
  int v, n;
  cin >> v >> n;
  p.resize(v + 1);
  for (int i = 0; i <= v; i++) {
    p[i] = i;
  }
  vector<int> zu(v + 1, 0);
  // for (auto x : zu) {
  //   cout << x << ' ';
  // }
  for (int i = 1; i <= n; i++) {
    int x1, x2;
    cin >> x1 >> x2;
    zu[x1]++;
    zu[x2]++;
    unionxx(x1, x2);
  }
  int a = findx(1);
  // for (int i = 1; i <= v; i++) {
  //   cout << findx(i) << ' ';
  // }
  // return 0;
  for (int i = 2; i <= v; i++) {
    if (findx(i) != a) {
      cout << 0;
      return 0;
    }
  }
  for (auto x : zu) {
    if (x % 2 != 0) {
      cout << 0;
      return 0;
    }
  }
  cout << 1;
  return 0;
}
