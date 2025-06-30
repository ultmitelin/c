#include <iostream>
#include <sstream>
using namespace std;
int main() {
  int n, m, s;
  cin >> n >> m >> s;
  int a[n + 1][n + 1];
  int dis[n + 1];

  fill_n(&a[0][0], (n + 1) * (n + 1), INT_MAX);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[x][y] = z;
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (a[j][i] != INT_MAX) {
        a[i][j] = a[j][i];
      }
    }
  }
  for (int i = 1; i < n + 1; i++) {
    dis[i] = a[s][i];
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
    }
  }

  // for (int i = 1; i < n + 1; i++) {
  //   for (int j = 1; j < n + 1; j++) {
  //     if (a[i][j] == INT_MAX)
  //       cout << 0 << ' ';
  //     else
  //       cout << a[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
}
