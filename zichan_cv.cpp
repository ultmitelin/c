#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
struct cv {
  long long c, v;
  bool flag;
  bool operator<(cv &a) { return this->v > a.v; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, w, k;
  cin >> n >> w >> k;
  vector<cv> zu(n);
  for (int i = 0; i < n; i++) {
    long long c, v;
    cin >> c >> v;
    zu[i].c = c;
    zu[i].v = v;
    zu[i].flag = 0;
  }
  sort(zu.begin(), zu.end());
  // for (auto &x : zu) {
  //   cout << x.c << ' ' << x.v << ' ' << x.flag << '\n';
  // }
  int ci = 0;
  while (ci < k) {
    // long long cha = LONG_LONG_MAX;
    long long vv = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (w - zu[i].c < 0) {
        continue;
      } else if (!zu[i].flag && zu[i].v > vv) {
        // cha = w - zu[i].c;
        pos = i;
        vv = zu[i].v;
      }
    }
    if (pos == -1) {
      break;
    } else {
      w += zu[pos].v;
      zu[pos].flag = 1;
      ci++;
    }
  }
  cout << w;
}