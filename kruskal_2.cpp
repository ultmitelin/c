#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
  int u, v, len;
  priority_queue<edge> roads;
  vector<edge> loseroads;

  for (int i = 0; i < m; i++) {
    cin >> u >> v >> len;
    roads.push(edge(u, v, len));
  }

  // edge x=roads.pop();
  // cout << roads.top() ;
  // roads.pop();

  vector<edge> mst;
  int min_cost = 0;
  int flag = 0;
  int last = 0;
  while (!roads.empty()) {
    flag = 0;
    edge x = roads.top();
    if (find(x.u) != find(x.v)) {
      unionxy(x.u, x.v);
      min_cost += x.len;
      mst.push_back(x);
      last = x.len;
      flag = 1;
    }
    if (!flag) {
      loseroads.push_back(roads.top());
    }
    roads.pop();
    // if (mst.size() == n - 1) {
    //   break;
    // }
  }

  if (mst.size() < n - 1) {
    cout << "NO MST" << '\n';
    set<int> kuai;
    for (int i = 1; i <= n; i++) {
      kuai.emplace(find(i));
    }
    cout << kuai.size();
    return 0;
  }
  sort(mst.begin(), mst.end());
  bool tong = false;
  int second_min = INT_MAX;
  for (edge& e : mst) {
    int without = min_cost - e.len;
    for (int i = 1; i <= n; parent[i] = i, i++);
    for (edge& ee : mst) {
      if (ee.u == e.u && ee.v == e.v && ee.len == e.len) {
        continue;
      }
      unionxy(ee.u, ee.v);
    }
    for (auto& ee : loseroads) {
      if (find(ee.u) != find(ee.v)) {
        without += ee.len;
        if (without == min_cost) {
          tong = true;
        }
        if (without < second_min) {
          second_min = without;
        }
        break;
      }
      // while (!loseroads.empty()) {
      //
      //   loseroads.pop();
    }
  }
  if (tong) {
    cout << "YES" << '\n' << min_cost;
    return 0;
  }
  if (second_min)
    // if (!loseroads.empty() && last > loseroads.top().len) {
    //   cout << "YES" << '\n' << min_cost;
    // } else {
    cout << "NO" << '\n';
  cout << min_cost << ' ';
  if (second_min == INT_MAX) {
    cout << -1;
  } else {
    cout << second_min;
  }

  return 0;
  // for (auto x : mst) {
  //   cout << x;
  // }
}
