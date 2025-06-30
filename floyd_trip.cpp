#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define INF INT_MAX

void optimizedFloydWarshallWithPath(vector<vector<int>>& graph,
                                    vector<vector<int>>& fee) {
  int V = graph.size();

  // 优化后的Floyd-Warshall核心算法
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      // 提前终止优化：如果i到k不可达则跳过
      if (graph[i][k] == INF) continue;

      for (int j = 0; j < V; j++) {
        // 空间优化：直接使用graph矩阵
        if (graph[k][j] != INF && graph[i][j] > graph[i][k] + graph[k][j]) {
          graph[i][j] = graph[i][k] + graph[k][j];
          fee[i][j] = fee[i][k] + fee[k][j];
        } else if (graph[i][j] == graph[i][k] + graph[k][j] &&
                   fee[i][k] + fee[k][j] < fee[i][j]) {
          fee[i][j] = fee[i][k] + fee[k][j];
        }
      }
    }
  }

  // 优化后的负权环检测
  for (int i = 0; i < V; i++) {
    if (graph[i][i] < 0) {
      cout << "警告：检测到负权环（顶点" << i << "）" << endl;
      return;
    }
  }
}

int main() {
  // 测试用例（包含负权边但不含负权环）
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  vector<vector<int>> graph(n, vector<int>(n, INF));
  vector<vector<int>> fee(n, vector<int>(n, INF));
  for (int i = 0; i < m; i++) {
    int u, v, l, f;
    cin >> u >> v >> l >> f;
    graph[u][v] = l;
    graph[v][u] = l;
    fee[u][v] = f;
    fee[v][u] = f;
  }
  optimizedFloydWarshallWithPath(graph, fee);
  cout << graph[s][d] << ' ' << fee[s][d];
  return 0;
}