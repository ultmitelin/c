#include <deque>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> zu(n + 1);  // zu[0] 未使用
  for (int i = 1; i <= n; ++i) {
    cin >> zu[i];
  }

  int t;
  cin >> t;

  deque<int> order;                       // 维护优先级顺序
  unordered_map<int, deque<int>> groups;  // 各优先级的子队列
  unordered_set<int> in_queue;            // 元素是否在队列中

  for (int i = 0; i < t; ++i) {
    string op;
    cin >> op;
    if (op[0] == 'D') {  // Dequeue操作
      if (order.empty()) {
        cout << -1 << '\n';
      } else {
        int p = order.front();
        int z = groups[p].front();
        cout << z << '\n';
        groups[p].pop_front();
        in_queue.erase(z);

        if (groups[p].empty()) {
          order.pop_front();
          groups.erase(p);
        }
      }
    } else {  // Enqueue操作
      int z;
      cin >> z;
      if (in_queue.count(z)) continue;
      // 用集合替代全体数组，可以不用逐个检查是否为empty；
      // 要维护的变多；但同时也更快

      int zv = zu[z];
      if (!groups.count(zv)) {
        order.push_back(zv);
        groups[zv] = deque<int>();
      }
      groups[zv].push_back(z);  // 插入到优先级组的头部
      in_queue.insert(z);
    }
  }
  return 0;
}

// #include <algorithm>
// #include <deque>
// #include <iostream>
// #include <vector>
// using namespace std;

// // void enque(int x);
// int main() {
//   int n;
//   cin >> n;
//   vector<int> zu(n + 1), zu1(n + 1);
//   zu[0] = 0;
//   zu1[0] = 0;
//   for (int i = 1; i <= n; cin >> zu[i], zu1[i] = zu[i], i++);

// 这两行找最大，也废了不少力
// 可以用函数，也可以学AI，map——queue 一起用 高！！！

//   sort(zu1.begin(), zu1.end());
//   int max = zu1[n];
//   vector<int> pos(max + 1);
//   bool tf[max + 1] = {};  // 要初始化，否则随机分配，不能全是0
//   //开了好多没用的空间
//   // cout << tf[1] << ' ' << tf[2] << endl;
//   int t;
//   cin >> t;
//   std::deque<int> dq;

//   for (int i = 0; i < t; i++) {
//     string x;
//     cin >> x;
//     switch (x[0]) {
//       case 'D': {
//         if (dq.empty()) {
//           cout << -1 << endl;
//         } else {
//           cout << dq.front() << endl;
//           if (dq.size() > 1 && zu[dq[0]] != zu[dq[1]]) {
//             tf[zu[dq[0]]] = 0;
//           } else if (dq.size() == 1) {
//             tf[zu[dq[0]]] = 0;
//           }
//           pos[zu[dq[0]]]--;

//           dq.pop_front();
//         }
//         break;
//       }
//       default: {
//         int z;
//         cin >> z;

//         if (tf[zu[z]]) {
//           if (find(dq.begin(), dq.end(), z) == dq.end()) {
//           //线性查找，太费时，直接push更快
//             // cout << "insert" << z << endl;
//             dq.insert(dq.begin() + pos[zu[z]], z);
//             //插入，就得先查找，性能就不够； for (int i = 0; i < max + 1;
//             i++) {
//               if (pos[zu[z]]) {
//                 pos[zu[z]]++;
//               }
//             }
//           }
//         } else {
//           // cout << "jin" << z << endl;
//           dq.push_back(z);
//           tf[zu[z]] = 1;
//           pos[zu[z]] = dq.size();
//         }
//         break;
//       }
//     }
//   }
// }