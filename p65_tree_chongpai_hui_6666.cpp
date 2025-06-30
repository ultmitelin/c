#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m, goal;
    cin >> m;
    vector<char> zu(m + 1);
    for (int i = 1; i <= m; cin >> zu[i++]);
    cin >> goal;
    unordered_map<char, int> map;
    while (goal) {
      map[zu[goal]]++;
      goal /= 2;
    }
    int flag = 0;
    for (auto x : map) {
      if (x.second % 2 != 0) {
        flag++;
      }
    }
    if (flag > 1) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
  }
}