#include <algorithm>  // 用于std::reverse
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> input(int r, int c) {
  vector<vector<int>> a;
  for (int i = 0; i < r; i++) {
    vector<int> x(c);
    for (int j = 0; j < c; j++) {
      // int a1 = 0;
      cin >> x[j];
      // x.push_back(a1);
    }
    a.push_back(x);
  }
  return a;
}
int main() {
  int r, c;
  cin >> r >> c;
  int num;
  cin >> num;
  // vector<vector<int>> a = input(r, c);
  vector<vector<int>> zu[num];
  for (int i = 0; i < num; i++) {
    zu[i] = input(r, c);
  }
  vector<vector<int>> result;
  for (int i = 0; i < num; i++) {
    if (i == 0) {
      result = zu[i];
    } else {
      for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
          result[j][k] += zu[i][j][k];
        }
      }
    }
  }
  // for (int i = 0; i < num; i++) {
  for (int j = 0; j < r; j++) {
    for (int k = 0; k < c; k++) {
      // cout << a[j][k] << ' ';
      cout << result[j][k] << ' ';
    }
    cout << endl;
  }
  // }
}