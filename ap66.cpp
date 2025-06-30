#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> weights(n + 1);
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    for (int j = 1; j <= n; cin >> weights[j++]);
    for (int j = 1; j <= n; cin >> l[j++]);
    for (int j = 1; j <= n; cin >> r[j++]);
    int root;
    cin >> root;
    bool flag = 0;
    function<int(int)> flmax = [&](int j) -> int {
      if (l[j] == n + 1) {
        return weights[j];
        // l[j] == n +
        // 1时，由&&的性质，该函数不会被调用，所以返回weights[j]就好；
        // 不能是任意值，后面会递归调用，要用到
      } else {
        int x = weights[j];
        int maxw = x;
        if (l[j] != n + 1) maxw = max(maxw, flmax(l[j]));
        if (r[j] != n + 1) maxw = max(maxw, flmax(r[j]));
        return maxw;
      }
    };
    function<int(int)> frmin = [&](int j) -> int {
      if (r[j] == n + 1) {
        return weights[j];
        // l[j] == n +
        // 1时，由&&的性质，该函数不会被调用，所以返回weights[j]就好；
      } else {
        int x = weights[j];
        int minw = x;
        if (l[j] != n + 1) minw = min(minw, flmax(l[j]));
        if (r[j] != n + 1) minw = min(minw, flmax(r[j]));
        return minw;
      }
      // if (r[j] == n + 1) {
      //   return INT_MAX;
      // } else {
      //   int x = weights[j];
      //   int min = x + 1;
      //   while (j > 0 && r[j] != n + 1) {
      //     if (flmax(r[j]) < min) {
      //       min = flmax(r[j]);
      //     }
      //     j--;
      //   }
      //   return min;
      // }
    };
    for (int j = 1; j <= n; j++) {
      int x = weights[j];
      //       3. 为什么调用 flmax(j) 和 frmin(j) 是错误的
      // 如果调用 flmax(j) 和 frmin(j)，那么函数会计算以节点 j
      // 为根的整个子树的最大值或最小值，而不是仅计算左子树或右子树的最大值或最小值。这与检查二叉树性质的逻辑不符。
      // 具体来说：
      // flmax(j) 会返回以节点 j 为根的子树的最大值，而不仅仅是左子树的最大值。
      // frmin(j) 会返回以节点 j 为根的子树的最小值，而不仅仅是右子树的最小值。
      if ((l[j] < n + 1 && flmax(l[j]) >= x) ||
          (r[j] < n + 1 && frmin(r[j]) <= x)) {
        flag = 1;
        break;
      }
    }

    if (flag) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
  }
  return 0;
}

// deepseek版
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

bool isValid(int node, long long min_val, long long max_val,
             vector<int>& weights, vector<int>& l, vector<int>& r, int n) {
  if (node == n + 1) {
    return true;
  }
  int val = weights[node];
  if (val <= min_val || val >= max_val) {
    return false;
  }
  return isValid(l[node], min_val, val, weights, l, r, n) &&
         isValid(r[node], val, max_val, weights, l, r, n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> weights(n + 1);
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> weights[i];
    }
    for (int i = 1; i <= n; ++i) {
      cin >> l[i];
    }
    for (int i = 1; i <= n; ++i) {
      cin >> r[i];
    }
    int root;
    cin >> root;
    if (isValid(root, LLONG_MIN, LLONG_MAX, weights, l, r, n)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}