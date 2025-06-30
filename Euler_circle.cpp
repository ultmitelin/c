// 从0开始编号的各顶点组成的无向图，判断是否有欧拉回路
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<int> parent;
int find(int x);
void unionxy(int x, int y);
void readEdges(int n, int m);
bool HaveEulerCircle();

int main() {
  int n, m;
  cout << "请输入顶点数和边数：" << endl;
  cin >> n >> m;
  if (m < n) {
    cout << "无欧拉回路。" << endl;
    return 0;
  }
  graph.resize(n);
  parent.resize(n, 0);
  for (int i = 0; i < n; parent[i] = i, i++);
  readEdges(n, m);
  if (HaveEulerCircle()) {
    cout << "有欧拉回路,谢谢使用。" << endl;
  } else {
    cout << "无欧拉回路,谢谢使用。" << endl;
  };
}

void readEdges(int n, int m) {
  int u, v;
  for (int i = 0; i < m;) {
    cout << "请输入第" << i + 1 << "条边（顶点编号从0到顶点数减一）：" << endl;
    cin >> u >> v;
    if (u >= n || v >= n || u < 0 || v < 0) {
      cout << "顶点编号不合法，请重新输入。\n";
      continue;
    }
    graph[u].push_back(v);
    graph[v].push_back(u);
    unionxy(u, v);
    ++i;
  }
}

int find(int x) {
  if (parent[x] == x) {
    return x;
  } else {
    return parent[x] = find(parent[x]);
  }
}
void unionxy(int x, int y) {
  int r1 = find(x);
  int r2 = find(y);
  if (r1 != r2) {
    parent[r2] = r1;
  }
  return;
}
bool HaveEulerCircle() {
  // TODO:判断是否有欧拉回路
  int p = find(0);
  for (int i = 1; i < parent.size(); i++) {
    if (find(i) != p) {
      return false;
    }
  }
  for (const auto& node : graph) {
    if (node.size() % 2 != 0) {
      return false;
    }
    return true;
  }
}