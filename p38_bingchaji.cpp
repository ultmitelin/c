#include <iostream>
#include <vector>
using namespace std;
vector<int> p;
vector<int> sz;
int maxsz = 1;
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
  // 一定是合并它们的根，而不是它们自己
  sz[rootx1] += sz[rootx2];
  if (sz[rootx1] > maxsz) {
    maxsz = sz[rootx1];
  }
  return;
}
int main() {
  int m, n;
  cin >> m >> n;
  p.resize(m + 1);
  // 从1开始计，要多分配一个
  sz.resize(m + 1);
  for (int i = 1; i <= m; i++) {
    p[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    int ges;
    cin >> ges;
    int s1, s;
    cin >> s1;
    for (int j = 2; j <= ges; j++) {
      cin >> s;
      unionxx(s1, s);
    }
  }

  cout << maxsz;
  return 0;
}