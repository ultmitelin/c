#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<bool>> mat;
struct dot {
  int i;
  int j;
};
vector<dot> v = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                 {0, 1},   {1, -1}, {1, 0},  {1, 1}};
int main() {
  int w, h;
  while (cin >> w >> h) {
    mat.resize(h, vector<bool>(w, 0));
    char c;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> c;
        if (c == '*') {
          mat[i][j] = 1;
        }
      }
    }
    int result = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (mat[i][j]) {
          mat[i][j] = 0;
          queue<dot> q;
          q.push({i, j});
          while (!q.empty()) {
            dot t = q.front();
            q.pop();
            for (int vv = 0; vv < 8; vv++) {
              if (t.i + v[vv].i >= 0 && t.i + v[vv].i < h &&
                  t.j + v[vv].j >= 0 && t.j + v[vv].j < w &&
                  mat[t.i + v[vv].i][t.j + v[vv].j]) {
                mat[t.i + v[vv].i][t.j + v[vv].j] = 0;
                q.push({t.i + v[vv].i, t.j + v[vv].j});
              }
            }
          }
          result++;
        }
      }
    }
    cout << result << '\n';
  }
}

// 第一遍：时间复杂度太高

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;
// vector<vector<bool>> mat;
// struct dot {
//   int i;
//   int j;
// };
// dot a;
// bool ok() {
//   int m = 0, n = 0;
//   for (auto xx : mat) {
//     n = 0;
//     for (auto x : xx) {
//       if (x == 1) {
//         a = {m, n};
//         return 0;
//       }
//       n++;
//     }
//     m++;
//   }
//   return 1;
// }

// vector<dot> v = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
//                  {0, 1},   {1, -1}, {1, 0},  {1, 1}};
// int main() {
//   int w, h;
//   while (cin >> w >> h) {
//     mat.resize(h, vector<bool>(w, 0));
//     char c;
//     for (int i = 0; i < h; i++) {
//       for (int j = 0; j < w; j++) {
//         cin >> c;
//         if (c == '*') {
//           mat[i][j] = 1;
//         }
//       }
//     }
//     int result = 0;
//     while (!ok()) {
//       // cout << a.i << ' ' << a.j;
//       // break;
//       queue<dot> q;
//       q.push(a);
//       while (!q.empty()) {
//         dot t = q.front();
//         q.pop();
//         for (int vv = 0; vv < 8; vv++) {
//           if (t.i + v[vv].i >= 0 && t.i + v[vv].i < h && t.j + v[vv].j >= 0
//           &&
//               t.j + v[vv].j < w && mat[t.i + v[vv].i][t.j + v[vv].j]) {
//             mat[t.i + v[vv].i][t.j + v[vv].j] = 0;
//             q.push({t.i + v[vv].i, t.j + v[vv].j});
//           }
//         }
//       }
//       result++;
//     }

//     cout << result << '\n';
//   }
// }