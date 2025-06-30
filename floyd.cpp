#include <climits>
#include <iostream>
#include <vector>

using namespace std;

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
    cout << "->" << u;
  }
}

void optimizedFloydWarshallWithPath(vector<vector<int>>& graph) {
  int V = graph.size();
  vector<vector<int>> next(V, vector<int>(V, -1));

  // 初始化next矩阵（空间优化：直接使用graph作为dist矩阵）
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (graph[i][j] != INF && i != j) {
        next[i][j] = j;
      }
    }
  }

  // 优化后的Floyd-Warshall核心算法
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      // 提前终止优化：如果i到k不可达则跳过
      if (graph[i][k] == INF) continue;

      for (int j = 0; j < V; j++) {
        // 空间优化：直接使用graph矩阵
        if (graph[k][j] != INF && graph[i][j] > graph[i][k] + graph[k][j]) {
          graph[i][j] = graph[i][k] + graph[k][j];
          next[i][j] = next[i][k];  // 更新路径
        }
      }
    }
  }

  // 打印结果（优化输出格式）
  cout << "最短路径结果：" << endl;
  cout << "起点\t终点\t距离\t路径" << endl;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (i != j && graph[i][j] != INF) {
        cout << i << "\t" << j << "\t" << graph[i][j] << "\t";
        printPath(next, i, j);
        cout << endl;
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
  vector<vector<int>> graph = {
      {0, 3, 6, 15}, {INF, 0, -2, INF}, {INF, INF, 0, 2}, {1, INF, INF, 0}};

  optimizedFloydWarshallWithPath(graph);

  return 0;
}