#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
  // 构建邻接表和入度数组
  vector<vector<int>> adj(n);  // 邻接表存储图结构
  vector<int> indegree(n, 0);  // 记录每个节点的入度

  // 遍历所有边构建图
  for (auto& edge : edges) {
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);  // 添加有向边u->v
    indegree[v]++;        // v的入度加1
  }

  queue<int> q;  // 维护当前入度为0的节点
  // 初始化队列：将所有初始入度为0的节点入队
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> result;  // 存储拓扑排序结果

  // Kahn算法核心过程
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    result.push_back(u);  // 将当前节点加入结果

    // 遍历所有邻接节点，减少它们的入度
    for (int v : adj[u]) {
      indegree[v]--;
      // 如果入度减为0，加入队列
      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  // 检查是否存在环
  if (result.size() != n) {
    return {};  // 存在环时返回空数组
  }
  return result;
}

int main() {
  int n, m;
  cout << "输入节点数和边数: ";
  cin >> n >> m;

  vector<vector<int>> edges(m, vector<int>(2));
  cout << "输入" << m << "条边（格式：起点 终点）:" << endl;
  for (int i = 0; i < m; ++i) {
    cin >> edges[i][0] >> edges[i][1];
  }

  vector<int> order = topologicalSort(n, edges);

  if (order.empty()) {
    cout << "图中存在环，无法进行拓扑排序！" << endl;
  } else {
    cout << "拓扑排序结果: ";
    for (int node : order) {
      cout << node << " ";
    }
    cout << endl;
  }

  return 0;
}