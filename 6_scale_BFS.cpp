#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> vis(n + 1, 0);
  // int time_stamp = 0;
  // 可以用i代替时间戳，节省空间

  // 4层循环：
  // 1：各个点
  // 2：进图开始bfs
  // 3：确定这层要进的分支，并pop
  // 4：这个分支全进队

  for (int i = 1; i <= n; i++) {
    double ratio;
    queue<int> x;
    x.push(i);
    // time_stamp = i;
    vis[i] = i;
    // vector<bool> vis(n + 1, false);
    // vis[i] = 1;
    // 时间戳技术；
    int level = 1;
    int count = 1;

    while (level <= 6 && !x.empty()) {
      int sz = x.size();
      for (int k = 0; k < sz; k++) {
        int st = x.front();
        x.pop();
        for (int j : g[st]) {
          // if (!vis[j]) {
          // if (vis[j] != time_stamp) {
          if (vis[j] != i) {
            x.push(j);
            // vis[j] = time_stamp;
            vis[j] = i;
            count++;
          }
        }
      }
      level++;
    }
    ratio = count * 100.00 / n;
    cout << i << ": " << fixed << setprecision(2) << ratio << "%\n";
  }
}

/*
deepseek —— BFS，bfs两层循环就够：定当前分支+分支入队
// 要记录层数的话，再加一层；
// 要全部节点st的话，再加一层
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// 使用邻接表表示图
vector<vector<int>> adj;  // 邻接表
vector<bool> visited;     // 记录节点是否被访问过

void bfs(int start) {
    queue<int> q;  // 创建队列用于BFS

    // 将起始节点加入队列并标记为已访问
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();  // 获取队列前端节点
        q.pop();                 // 移除队列前端节点

        cout << "正在访问节点: " << current << endl;

        // 遍历当前节点的所有邻居
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;  // 标记为已访问
                q.push(neighbor);          // 加入队列
            }
        }
    }
}

int main() {
    // 示例：构建一个简单的图
    int n = 6;  // 节点数量
    adj.resize(n);
    visited.resize(n, false);

    // 添加边 (无向图)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[3].push_back(5);
    adj[4].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(3);
    adj[5].push_back(4);

    cout << "BFS 遍历顺序:" << endl;
    bfs(0);  // 从节点0开始BFS

    return 0;
}*/