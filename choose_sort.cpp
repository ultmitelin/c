#include <iostream>
#include <vector>
using namespace std;
void sort1(vector<int>& zu, int n) {
  for (int i = 0; i < n - 1; i++) {
    int flag = i;
    for (int j = i + 1; j < n; j++) {
      if (zu[j] < zu[flag]) {
        flag = j;
      }
    }
    if (flag != i) {
      swap(zu[i], zu[flag]);
    }
  }
  return;
}
int main() {
  vector<int> zu;
  int x;
  while (cin >> x) {
    zu.push_back(x);
  }
  for (auto x : zu) {
    cout << x << ' ';
  }
  cout << '\n';
  sort1(zu, zu.size());
  for (auto x : zu) {
    cout << x << ' ';
  }
}