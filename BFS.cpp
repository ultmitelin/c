#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// 使用邻接表表示图
class Graph {
  int V;                    // 顶点数量
  vector<vector<int>> adj;  // 邻接表

 public:
  Graph(int V) : V(V), adj(V) {}

  // 添加边
  void addEdge(int v, int w) { adj[v].push_back(w); }

  // 从顶点s开始的BFS遍历
  void BFS(int s) {
    // 记录已访问的顶点
    vector<bool> visited(V, false);

    // 创建BFS队列
    queue<int> q;

    // 标记当前节点为已访问并入队
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
      // 取出队首顶点
      int current = q.front();
      q.pop();
      cout << current << " ";

      // 获取所有邻接顶点
      for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
  }
};

int main() {
  // 创建一个有5个顶点的图
  Graph g(5);

  // 添加边
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 4);
  g.addEdge(3, 4);

  cout << "从顶点0开始的BFS遍历结果:\n";
  g.BFS(0);

  return 0;
}