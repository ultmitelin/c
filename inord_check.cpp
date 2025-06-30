#include <iostream>
#include <vector>
using namespace std;
vector<int> midord;
void mid(vector<int>& t, int i) {
  int n = t.size();
  if (i >= n) {
    return;
  }

  mid(t, 2 * i + 1);

  midord.push_back(t[i]);

  mid(t, 2 * i + 2);
}
int main() {
  int z;
  cin >> z;
  for (int i = 0; i < z; i++) {
    int n;
    cin >> n;
    vector<int> tree(n);
    midord.clear();  // 确保清空
    for (int j = 0; j < n; cin >> tree[j++]);
    // vector<int> midord=mid(tree);
    mid(tree, 0);
    int last = midord[0];
    bool flag = 0;
    // for (int i = 1; i < n; i++) {内层不能再用i
    for (int j = 1; j < n; j++) {
      if (midord[j] <= last) {
        cout << "No" << '\n';
        flag = 1;
        break;
      } else {
        last = midord[j];
      }
    }
    if (!flag) {
      cout << "Yes" << '\n';
    }
    // for (auto x : midord) {
    //   cout << x << ' ';
    // }
    // cout << '\n';
    midord.clear();
  }
}

// ds最优法 隐式中序
/*#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool inOrderCheck(vector<int>& tree, int i, int n, int& prev, bool& firstVisit)
{ if (i >= n) return true;

    // 递归左子树 (2*i+1)
    if (!inOrderCheck(tree, 2*i+1, n, prev, firstVisit))
        return false;

    // 检查当前节点
    if (firstVisit) {
        firstVisit = false;
        prev = tree[i];
    } else {
        if (tree[i] <= prev)  // 非严格递增（含重复值）
            return false;
        prev = tree[i];
    }

    // 递归右子树 (2*i+2)
    return inOrderCheck(tree, 2*i+2, n, prev, firstVisit);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<int> tree(n);
        for (int i = 0; i < n; i++) {
            cin >> tree[i];
        }

        int prev = INT_MIN;
        bool firstVisit = true;
        bool is_bst = inOrderCheck(tree, 0, n, prev, firstVisit);

        cout << (is_bst ? "Yes" : "No") << '\n';
    }
    return 0;
}*/