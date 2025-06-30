#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> zu;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    zu.push_back(a);
  }
  sort(zu.begin(), zu.end());
  // for (int i = 0; i < n; cout << zu[i++]);
  vector<int> add;
  for (int i = 0; i < n / 2; i++) {
    int x = zu[i] + zu[n - 1 - i];
    add.push_back(x);
  }
  sort(add.begin(), add.end());
  cout << add[n / 2 - 1];
}
// 这个思路好，本来想着试一试，没想到成了
// 往可能的方向走，有想法就干，别犹豫
// vector也可以设置大小，然后直接输入（不用让a当temp）
// /它是每次算完当场比较得出最大；我后面再排，大差不差
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  // 排序
  std::sort(a.begin(), a.end());

  // 配对并找到最大值
  int max_sum = INT_MIN;
  for (int i = 0; i < n / 2; ++i) {
    int sum = a[i] + a[n - i - 1];
    if (sum > max_sum) {
      max_sum = sum;
    }
  }

  // 输出最大值
  std::cout << max_sum << std::endl;

  return 0;
}