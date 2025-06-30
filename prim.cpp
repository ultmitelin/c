#include <climits>
#include <iostream>
#include <vector>
using namespace std;
const int INF = INT_MAX;
void prim(vector<vector<int>> g, int start) {
  int n = g.size() - 1;
  vector<int> key(n + 1, INF);
  vector<int> parent(n + 1, -1);
  vector<bool> inMST(n + 1, false);
  key[start] = 0;
  parent[start] = -1;
  for (int edges = 0; edges < n; edges++) {
    int u = -1, minl = INF;
    for (int v = 1; v <= n; v++) {
      if (!inMST[v] && key[v] < minl) {
        minl = key[v];
        u = v;
      }
    }
    if (u == -1) {
      cout << "-1\n";  // 输出 -1 表示无法生成最小生成树
      return;
    }
    inMST[u] = true;
    for (int v = 1; v <= n; v++) {
      if (g[u][v] && (!inMST[v]) && g[u][v] < key[v]) {
        parent[v] = u;
        key[v] = g[u][v];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!inMST[i]) {
      cout << "-1\n";  // 输出 -1 表示无法生成最小生成树
      return;
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (parent[i] == -1) {
      continue;
    }
    sum += key[i];
    // cout << parent[i] << '-' << i << ' ' << key[i] << '\n';
  }
  cout << sum;
  return;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graphic(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; i++) {
    int u, v, weight;
    cin >> u >> v >> weight;
    graphic[u][v] = weight;
    graphic[v][u] = weight;
  }
  int start = 1;
  // cin >> start;
  prim(graphic, start);
  return 0;
}