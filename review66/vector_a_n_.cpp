#include <iostream>
using namespace std;
#include <vector>
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  // 索引越界：for 循环的条件应该是 i < n 而不是 i < n + 2。
  // 当前的循环会尝试访问 a[n] 和
  // a[n+1]，这超出了向量的有效范围，因为n表示向量的元素个数，最后一个有效索引是
  // n - 1。
  for (int i = 0; i < n + 2; cin >> a[i], cout << a[i++]);
}