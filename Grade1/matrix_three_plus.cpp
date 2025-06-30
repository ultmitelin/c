#include <algorithm>  // 用于std::reverse
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<long>> input(int m, int r, int c) {
  vector<vector<long>> a(r, vector<long>(c));
  for (int i = 0; i < m; i++) {
    int r, c, val;
    cin >> r >> c >> val;
    a[r][c] = val;
  }
  return a;
}
int main() {
  vector<vector<vector<long>>> zu(2);
  // for (int m = 0; m < 2; m++) {
  int r, c;
  cin >> r >> c;
  int num;
  cin >> num;
  // vector<vector<long>> a = input(r, c);
  zu[0] = input(num, r, c);
  // }
  // int r, c;
  cin >> r >> c;
  // int num;
  cin >> num;
  // vector<vector<long>> a = input(r, c);
  zu[1] = input(num, r, c);

  vector<vector<long>> result;
  for (int i = 0; i < 2; i++) {
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
      // cout << result[j][k] << ' ';
      if (result[j][k] != 0)
        cout << j << ' ' << k << ' ' << result[j][k] << endl;
    }
    // cout << endl;
  }
  // }
}