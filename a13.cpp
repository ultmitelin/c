#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAXN = 1e4 + 7;  // 节点的最大数量加上一些缓冲区大小
typedef pair<int, int> PII;
#define INF INT_MAX

// 题目描述中涉及的大致范围设定全局变量
int N, M, S;

long long dist[MAXN];
int pathCnt[MAXN];

struct Edge {
  int to;
  int cost;
};

vector<Edge> adjList[MAXN];  // 图的邻接表表示法

void solve() {
  priority_queue<PII, vector<PII>, greater<PII>> pq;

  memset(dist, 0x3f, sizeof dist);  // 初始化dist数组为最大值
  fill(pathCnt, pathCnt + MAXN, 0);

  dist[S] = 0LL;
  pathCnt[S] = 1;
  pq.push({0, S});

  while (!pq.empty()) {
    auto [d, curNode] = pq.top();
    pq.pop();

    if (d != dist[curNode]) continue;

    for (auto &edge : adjList[curNode]) {
      const int nextCost = d + edge.cost;

      if (nextCost < dist[edge.to]) {
        dist[edge.to] = nextCost;
        pathCnt[edge.to] = pathCnt[curNode];
        pq.emplace(nextCost, edge.to);
      } else if (nextCost == dist[edge.to]) {
        pathCnt[edge.to] += pathCnt[curNode];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  cin >> N >> M >> S;
  --S;  // 把源点转换成0索引系统

  for (int i = 0; i < M; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    --from, --to;  // 同样把节点坐标转为0开始编号方便后续处理
    adjList[from].push_back({to, cost});
  }

  solve();

  for (int i = 0; i < N; ++i) {
    if (i != S) cout << dist[i] << " " << pathCnt[i] << '\n';
  }

  return 0;
}