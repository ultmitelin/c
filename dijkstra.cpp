#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = INT_MAX;  // 表示无穷大（不可达）

// 边的结构体：目标节点 v，权重 w，相同边的数量 cnt
struct Edge {
  int v, w, cnt;
  Edge(int v, int w, int cnt) : v(v), w(w), cnt(cnt) {}
};

// 优先队列的节点：当前节点 u，距离 d
struct Node {
  int u, d;
  Node(int u, int d) : u(u), d(d) {}
  // 重载 > 运算符，用于最小堆
  bool operator>(const Node& other) const { return d > other.d; }
};

vector<vector<Edge>> adj;  // 邻接表存储图
vector<int> dis;           // dis[u] = 源点 s 到 u 的最短距离
vector<long long> cnt;     // cnt[u] = 源点 s 到 u 的最短路径数量

// Dijkstra 算法实现（带路径计数）
void dijkstra(int s) {
  priority_queue<Node, vector<Node>, greater<Node>> pq;  // 最小堆
  dis[s] = 0;                                            // 源点到自己的距离为 0
  cnt[s] = 1;  // 源点到自己的路径数为 1
  pq.push(Node(s, 0));

  while (!pq.empty()) {
    Node node = pq.top();
    pq.pop();
    int u = node.u;
    // 如果当前距离 > 已知最短距离，说明该节点已被更优路径处理过，跳过
    if (node.d > dis[u]) continue;

    // 遍历 u 的所有邻边
    for (const Edge& e : adj[u]) {
      int v = e.v;
      int new_dis = dis[u] + e.w;  // 新距离 = u 的最短距离 + 边权

      // 如果新距离更短，更新 dis[v] 和 cnt[v]
      if (new_dis < dis[v]) {
        dis[v] = new_dis;
        cnt[v] = cnt[u] * e.cnt;    // 路径数 = u 的路径数 × 边数
        pq.push(Node(v, new_dis));  // 加入优先队列
      }
      // 如果新距离等于已知最短距离，累加路径数
      else if (new_dis == dis[v]) {
        cnt[v] += cnt[u] * e.cnt;
      }
    }
  }
}

int main() {
  int n, m, s;
  cin >> n >> m >> s;  // 输入节点数、边数、源点

  // 初始化
  adj.resize(n + 1);
  dis.resize(n + 1, INF);
  cnt.resize(n + 1, 0);

  // 输入边，并合并重边
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    // 检查是否已有 u→v 的边
    bool found = false;
    for (Edge& e : adj[u]) {
      if (e.v == v) {
        if (w < e.w) {  // 如果新边更短，更新
          e.w = w;
          e.cnt = 1;
        } else if (w == e.w) {  // 如果权重相同，增加计数
          e.cnt++;
        }
        found = true;
        break;
      }
    }
    // 如果没有找到，添加新边
    if (!found) {
      adj[u].emplace_back(v, w, 1);
    }
  }

  // 运行 Dijkstra
  dijkstra(s);

  // 输出结果
  for (int i = 1; i <= n; ++i) {
    if (i == s) continue;  // 跳过源点
    if (dis[i] == INF)
      cout << "0 0\n";  // 不可达
    else
      cout << dis[i] << ' ' << cnt[i] << '\n';  // 最短距离 + 路径数
  }

  return 0;
}
// 朴素版
// #include <algorithm>
// #include <climits>
// #include <functional>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <vector>
// using namespace std;
// const int INF = INT_MAX;
// vector<bool> ding;
// vector<int> dis;
// vector<int> path;
// int nexts;
// void renew(vector<vector<int>>& g, int s) {
//   int n = g.size() - 1;
//   // ding[s]=1;
//   for (int i = 1; i <= n; i++) {
//     if (g[s][i] != INF && dis[s] + g[s][i] < dis[i]) {
//       dis[i] = dis[s] + g[s][i];
//       path[i] = s;
//     }
//   }
// }
// bool ok() {
//   for (int i = 1; i <= (int)(ding.size() - 1); i++) {
//     if (!ding[i]) {
//       return 0;
//     }
//   }
//   return 1;
// }
// int main() {
//   int n, m, s;
//   cin >> n >> m >> s;
//   // vis.resize(n + 1, 0);
//   ding.resize(n + 1, false);
//   dis.resize(n + 1, INF);
//   path.resize(n + 1, -1);
//   vector<vector<int>> g(n + 1, vector<int>(n + 1, INF));
//   for (int i = 0; i < m; i++) {
//     int u, v, w;
//     cin >> u >> v >> w;
//     g[u][v] = w;
//   }
//   // int s = 1;
//   nexts = s;
//   ding[s] = 1;
//   dis[s] = 0;
//   while (!ok()) {
//     renew(g, nexts);
//     int mind = INF;
//     nexts = -1;
//     for (int i = 1; i <= n; i++) {
//       if (!ding[i] && dis[i] < mind) {
//         mind = dis[i];
//         nexts = i;
//       }
//     }
//     if (nexts == -1) {
//       break;  // No reachable nodes left
//     }
//     ding[nexts] = 1;
//   }
//   for (int i = 1; i <= n; i++) {
//     if (i == s) {
//       continue;
//     }
//     cout << dis[i] << ' ' << 1 << '\n';
//   }
// }
