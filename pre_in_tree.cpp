#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> post_;
void hou(vector<int> pre_, vector<int> in_, int l, int r, int p_s) {
  if (l > r) {
    return;
  }
  auto it = find(in_.begin(), in_.end(), pre_[p_s]);
  int pos = it - in_.begin();

  if (pos - 1 >= l) {  // 这样可以避免不必要的递归调用，提高程序效率和安全性。
    hou(pre_, in_, l, pos - 1, p_s + 1);
  }
  if ((pos + 1 <= r)) {
    hou(pre_, in_, pos + 1, r, p_s + pos - l + 1);
  }
  post_.push_back(*it);
}
int main() {
  int x;
  vector<int> pre_;

  while (cin >> x) {
    pre_.push_back(x);
  }
  vector<int> in_ = pre_;
  sort(in_.begin(), in_.end());
  // for (auto x : pre_) {
  //   cout << x << ' ';
  // }
  // cout << endl;
  // for (auto x : in_) {
  //   cout << x << ' ';
  // }
  // cout << endl;
  hou(pre_, in_, 0, in_.size() - 1, 0);
  for (auto x : post_) {
    cout << x << '\n';
  }
}