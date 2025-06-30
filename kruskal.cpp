#include <functional>
#include <iostream>
#include <map>
#include <queue>
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
};
struct edge {
  int u;
  int v;
  int len;
  bool operator<(const edge& a) const { return this->len > a.len; }
  edge(int a, int b, int c) {
    u = a;
    v = b;
    len = c;
  }

  friend ostream& operator<<(ostream& o, const edge e) {
    o << e.u << ' ' << e.v << ' ' << e.len << '\n';
    return o;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  // vector<int> xcost(n);
  // for (int i = 0; i < n; cin >> xcost[i++]);

  parent.resize(n + 1);
  for (int i = 1; i <= n; parent[i] = i, i++);
  int u, v, len;
  priority_queue<edge> roads;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> len;
    roads.push(edge(u, v, len));
  }
  vector<edge> mst;
  int min_cost = 0;
  while (!roads.empty()) {
    edge x = roads.top();
    if (find(x.u) != find(x.v)) {
      unionxy(x.u, x.v);
      min_cost += x.len;
      mst.push_back(x);
    }
    roads.pop();
    if (mst.size() == n) {
      break;
    }
  }
  if (mst.size() < n) {
    cout << -1;
  } else
    cout << min_cost;
  return 0;
}
// min_cost *= c;
// int minp = xcost[0];
// for (int i = 1; i < n; i++) {
//   if (xcost[i] < minp) {
//     minp = xcost[i];
//   }
// }

// min_cost += minp;

// map<int, int> xci;
// for (auto x : mst) {
//   xci[x.u]++;
//   xci[x.v]++;
// }
// for (auto x : xci) {
//   if (x.second == 1) {
//     for (edge& y : mst) {
//       if (y.u == x.first || y.v == x.first) {
//         if (y.len * c > xcost[x.first - 1]) {
//           y.len = 0;
//           min_cost += xcost[x.first - 1];
//           xcost[x.first - 1] = 100000;
//         }
//       }
//     }
//   }
// }
// // 不给这个村修路之后，村的个数减少，最小生成树改变，不能这么操作