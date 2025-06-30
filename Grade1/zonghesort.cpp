#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
struct a {
  vector<int> line;
  int lid;
};
int hi(int a) {
  if (a < 0) a = (-a);
  while (a >= 10) {
    a = a / 10;
  }
  // a<0时要先取绝对值
  return a;
}
// 比较函数用引用，减小内存占用；要全部考虑到
bool cmp1(int &a, int &b) {
  if (hi(a) != hi(b)) return hi(a) > hi(b);
  return a < b;
}
int count(vector<int> &a) {
  int d = 1;
  for (int i = 1; i < (int)a.size(); i++) {
    if (a[i] != a[i - 1]) d++;
  }
  return d;
}
bool cmp2(a &l1, a &l2) {
  if (count(l1.line) != count(l2.line)) return count(l1.line) > count(l2.line);
  return l1.lid < l2.lid;
}
int main() {
  int m, n;
  cin >> m >> n;
  a rows[m];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int b;
      cin >> b;
      rows[i].line.push_back(b);
    }
    sort(rows[i].line.begin(), rows[i].line.end(), cmp1);
    rows[i].lid = i;
  }
  sort(rows, rows + m, cmp2);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (j == 0 || rows[i].line[j] != rows[i].line[j - 1])
        cout << rows[i].line[j] << ' ';
    }
    cout << endl;
  }
}