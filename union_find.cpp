#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
int find(int x) {
  if (parent[x] == x) {
    return x;
  } else {
    return parent[x] = find(parent[x]);
  }
}
void unionxy(int x, int y) {
  int r1 = find(x);
  int r2 = find(y);
  if (r1 != r2) {
    parent[r2] = r1;
  }
  return;
}

int main() {
  int n, m;
  cin >> n >> m;
  parent.resize(n + 1);
  for (int i = 1; i <= n; parent[i] = i, i++);
  for (int i = 0; i < m; i++) {
    int op, a, b;
    cout << "请输入操作类型(0:合并 1:查询)和两个元素：";
    cin >> op >> a >> b;

    if (op == 0) {
      unionxy(a, b);  // 合并操作
    } else {
      if (find(a) == find(b)) {
        cout << a << " 和 " << b << " 在同一集合中" << endl;
      } else {
        cout << a << " 和 " << b << " 不在同一集合中" << endl;
      }
    }
  }
}