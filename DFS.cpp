#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> vis;
vector<int> out;
void dfs(vector<vector<int>> &g, int s) {
  cout << s << ' ';
  out.push_back(s);
  vis[s] = 1;
  for (int x : g[s]) {
    if (!vis[x]) {
      dfs(g, x);
      // cout << s << ' ';
      // 带回溯
    }
  }
}
int main() {
  int n, m, s;
  cin >> n >> m >> s;
  vis.resize(n + 1, 0);
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u != v) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
  }

  dfs(g, s);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cout << 0;
      break;
    }
  }
  return 0;
}