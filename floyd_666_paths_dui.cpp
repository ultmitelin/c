#include <climits>
#include <iostream>
#include <vector>

using namespace std;
vector<int> x_teams;
vector<vector<int>> teams;
vector<vector<int>> paths;
#define INF INT_MAX

void printPath(const vector<vector<int>>& next, int u, int v) {
  if (u == v) {
    std::cout << u;
    return;
  }
  if (next[u][v] == -1) {
    cout << "无路径";
    return;
  }

  cout << u;
  while (u != v) {
    u = next[u][v];
    cout << ' ' << u;
  }
}

void optimizedFloydWarshallWithPath(vector<vector<int>>& graph,
                                    vector<vector<int>>& next) {
  int V = graph.size() - 1;
  // 初始化next矩阵（空间优化：直接使用graph作为dist矩阵）
  for (int i = 1; i <= V; i++) {
    for (int j = 1; j <= V; j++) {
      if (graph[i][j] != INF && i != j) {
        next[i][j] = j;
      }
    }
  }

  // 优化后的Floyd-Warshall核心算法
  for (int k = 1; k <= V; k++) {
    for (int i = 1; i <= V; i++) {
      // 提前终止优化：如果i到k不可达则跳过
      if (graph[i][k] == INF) continue;

      for (int j = 1; j <= V; j++) {
        // 空间优化：直接使用graph矩阵
        if (graph[k][j] != INF) {
          if (graph[i][j] > graph[i][k] + graph[k][j]) {
            graph[i][j] = graph[i][k] + graph[k][j];
            next[i][j] = next[i][k];  // 更新路径
            teams[i][j] = teams[i][k] + teams[k][j] - x_teams[k];
            paths[i][j] = paths[i][k] * paths[k][j];
          } else if (graph[i][j] == graph[i][k] + graph[k][j]) {
            paths[i][j] += paths[i][k] * paths[k][j];
            // 路径相等的时候就要更新路径了，路径和队伍数量的问题是分离的，不能绑在下面的if里面
            if (teams[i][j] < teams[i][k] + teams[k][j]) {
              next[i][j] = next[i][k];  // 更新路径
              // cout << "renew" << i << ' ' << j << endl;
              teams[i][j] = teams[i][k] + teams[k][j] - x_teams[k];
            }
          }
        }
      }
    }
  }

  // 优化后的负权环检测
  for (int i = 1; i <= V; i++) {
    if (graph[i][i] < 0) {
      cout << "警告：检测到负权环（顶点" << i << "）" << endl;
      return;
    }
  }
}

int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
  teams.resize(n + 1, vector<int>(n + 1, 0));
  paths.resize(n + 1, vector<int>(n + 1, 0));
  vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));
  x_teams.resize(n + 1);
  for (int i = 1; i <= n; cin >> x_teams[i++]);
  for (int i = 1; i <= n; i++) {
    graph[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    graph[u][v] = l;
    graph[v][u] = l;
    teams[u][v] = x_teams[u] + x_teams[v];
    teams[v][u] = x_teams[u] + x_teams[v];
    paths[u][v] = 1;
    paths[v][u] = 1;
  }
  optimizedFloydWarshallWithPath(graph, next);
  cout << paths[s][d] << ' ' << teams[s][d] << '\n';
  // cout << paths[1][4] << endl;
  printPath(next, s, d);
  return 0;
}