// a
#include <cmath>
#include <iostream>
using namespace std;
int main() {
  long long a1, a2, b1, b2, c1, c2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;
  cin >> c1 >> c2;
  long long sum = 0;
  for (long long i = a1; i <= a2; i++) {
    for (long long j = b1; j <= b2; j++) {
      long long min = abs(i - j) + 1;
      long long max = i + j - 1;
      min = min < c1 ? c1 : min;
      max = max > c2 ? c2 : max;
      if (max >= min) sum += max - min + 1;
    }
  }
  cout << sum << endl;

  return 0;
}
// b
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n, dir;
  char a[100010], b[100010], c[100010], d[100010];
  scanf("%d%d\n", &n, &dir);
  for (int i = 1; i <= n; i++) scanf("%c", &a[i]);
  scanf("\n");
  for (int i = 1; i <= n; i++) scanf("%c", &b[i]);
  int i;
  if (dir == 1) {
    for (i = n; i > 1; i--) c[i] = a[i - 1];
    c[1] = b[1];
    for (i = 1; i < n; i++) d[i] = b[i + 1];
    d[n] = a[n];
    for (int i = 1; i <= n; i++) printf("%c", c[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) printf("%c", d[i]);
  } else {
    for (i = 1; i < n; i++) c[i] = a[i + 1];
    c[n] = b[n];
    for (i = n; i > 1; i--) d[i] = b[i - 1];
    d[1] = a[1];
    for (int i = 1; i <= n; i++) printf("%c", c[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) printf("%c", d[i]);
  }
  return 0;
}
// c

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(n);
  for (int i = 0; i < n; i++) {
    int m, x;
    cin >> m;
    for (int j = 1; j <= m; j++) {
      cin >> x;
      a[i].push_back(x);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = a[i].size() - 1; j >= 0; j--) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
// d
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
struct hhh {
  int x;
  int y;
};
bool cmp(hhh a, hhh b) {
  if (a.y == b.y) return a.x > b.x;
  return a.y > b.y;
}
int main() {
  int n;
  cin >> n;
  int f[100010], cnt = 0;
  hhh a[40010];
  bool flag;

  for (int i = 2; i <= 400; i++) {
    flag = true;
    for (int j = 2; j <= sqrt(i); j++)
      if (i % j == 0) {
        flag = false;

        break;
      }
    if (flag) f[++cnt] = i;
  }

  for (int i = 0; i < n; i++) {
    cin >> a[i].x;
    int ans = 0;
    for (int j = 1; j <= cnt && f[j] <= a[i].x; j++) {
      if (a[i].x % f[j] == 0) ans++;
    }
    a[i].y = ans;
  }
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i++) cout << a[i].x << ' ';
  cout << endl;
  return 0;
}

// e
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  double l1, d1, l2, d2, l;
  cin >> l1 >> d1 >> l2 >> d2 >> l;
  double ll = l2 - l1;
  double x = pow(10, log10(d2 / d1) / ll);

  printf("%.15lf", d1 * pow(x, l - l1));
  return 0;
}

// f
#include <iostream>
using namespace std;
int w;
long long f(int t);
int main() {
  int T, tt;
  cin >> T;

  for (tt = 1; tt <= T; tt++) {
    cin >> w;

    cout << f(w) << endl;
  }
  return 0;
}

long long f(int t) {
  if (t == 0) return 0;
  if (t == 1) return 1;
  int cnt = 0, ans = 0;
  int a[520];
  for (int x = t; x > 0; a[cnt++] = x & 1, ans += x & 1, x = x >> 1);

  if (ans % 2 == 0) {
    int x = 0, y = 0;
    int i;
    for (i = 0; i < cnt && y < ans / 2; x += a[i] * (1 << i), y += a[i], i++);
    int x1 = x;
    x = 0;
    while (a[i] != 1) i++;
    y = i;
    for (; i < cnt; x += a[i] * (1 << (i - y)), i++);
    int x2 = x;
    return t + f(x1) + f(x2);
  } else {
    int i;
    int y = 0;
    for (i = 0; i < cnt && y < (ans + 1) / 2; y += a[i], i++);
    i--;
    int mid = i;
    int x1 = 0, x2 = 0, x3 = 0;
    for (i = 0; i <= mid - 1; i++) x1 += a[i] * (1 << (i));
    x2 = 1;
    i++;
    for (; i < cnt; i++) x3 += a[i] * (1 << (i - mid - 1));
    return t + f(x1) + f(x2) + f(x3);
  }
}