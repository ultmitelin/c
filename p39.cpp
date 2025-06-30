
// 理解规则，理解题目是最重要的，
// 按他的意思，敌人的敌人的敌人就是敌人，按逻辑分队就好了，别想那么复杂，
// ok，他给的用例肯定是符合他的规则的
// 现实生活中，敌人的关系不具有传递性，但他的意思就是有，所以别多想，按这个规则分队就好
// 灵活，别纠结，别固执，这只是个题，ac就好，不必较真

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> parent;
vector<int> rank1;

int find(int x) {
  if (parent[x] == x) {
    return x;  // 如果当前节点的父节点是自己，说明已经找到根节点
  }
  // 递归查找根节点，并将当前节点的父节点直接指向根节点（路径压缩）
  parent[x] = find(parent[x]);
  return parent[x];
}

// int find(int x, vector<int>& parent) {
//     int root = x;
//     while (parent[root] != root) {
//         root = parent[root];
//     }
//     while (x != root) {
//         int next = parent[x];
//         parent[x] = root;
//         x = next;
//     }
//     return root;
// }

void unite(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy) return;
  if (rank1[fx] < rank1[fy]) {
    parent[fx] = fy;
  } else {
    parent[fy] = fx;
    if (rank1[fx] == rank1[fy]) {
      rank1[fx]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    parent.resize(2 * n + 1);
    rank1.resize(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
      parent[i] = i;
    }

    while (m--) {
      char op;
      int x, y;
      cin >> op >> x >> y;
      if (op == 'A') {
        unite(x, y + n);
        unite(y, x + n);
      } else if (op == 'Q') {
        int x_root = find(x);
        int y_root = find(y);
        int x_enemy_root = find(x + n);
        int y_enemy_root = find(y + n);

        if (x_root == y_root || x_enemy_root == y_enemy_root) {
          cout << "In the same gang." << endl;
        } else if (x_root == find(y + n) || find(x + n) == y_root) {
          cout << "In different gangs." << endl;
        } else {
          cout << "Not sure yet." << endl;
        }
      }
    }
  }
  return 0;
}