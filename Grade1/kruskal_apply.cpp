#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int u;     // 起点
  int v;     // 终点
  int cost;  // 边的代价

  bool operator<(const Edge& e) const { return this->cost < e.cost; }
};

int father[1005];  // 并查集数组

// 查找祖先函数，并做路径压缩优化
int find(int x) {
  if (x != father[x]) father[x] = find(father[x]);
  return father[x];
}

void Kruskal(vector<Edge>& edges, int n) {
  sort(edges.begin(), edges.end());  // 按照cost从小到大排序

  for (int i = 1; i <= n; ++i) father[i] = i;  // 初始化并查集

  int minCost = 0;
  int cnt = 0;

  for (auto& edge : edges) {
    int fu = find(edge.u);
    int fv = find(edge.v);

    if (fu != fv) {  // 如果不在同一个集合内，则合并
      father[fv] = fu;
      ++cnt;
      minCost += edge.cost;
      // cout << edge.u << ' ' << edge.v << ' ' << edge.cost << endl;
      if (cnt ==
          n - 1)  // 当恰好选择了n-1条边的时候说明已经找到了一颗完整的MST了
        break;
    }
  }

  if (cnt < n - 1)
    cout << -1 << endl;  // 无法联通所有的村庄
  else
    cout << minCost << endl;
}

int main() {
  int N, M;

  cin >> N >> M;

  vector<Edge> roads(M);

  for (int i = 0; i < M; ++i) {
    cin >> roads[i].u >> roads[i].v >> roads[i].cost;
  }

  Kruskal(roads, N);
  // for (int i = 0; i < M;
  //      cout << roads[i].u << ' ' << roads[i].v << ' ' << roads[i].cost <<
  //      endl,
  //          i++);
}