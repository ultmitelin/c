#include <algorithm>
#include <iostream>
using namespace std;
struct zu {
  long long a;
  long long b;
};
bool cmp(zu a1, zu b1) {
  if (abs(a1.a) - abs(b1.b) == abs(b1.a) - abs(a1.b)) {
    if (a1.a != b1.a)
      return a1.a < b1.a;
    else
      return a1.b < b1.b;
  }
  return abs(a1.a) - abs(b1.a) > abs(b1.b) - abs(a1.b);  // 不用+防止越界
}
int main() {
  int n;
  cin >> n;
  zu xv[100];
  for (int i = 0; i < n; i++) {
    cin >> xv[i].a >> xv[i].b;
  }
  sort(xv, xv + n, cmp);
  for (int j = 0; j < n; j++) {
    cout << "(" << xv[j].a << "," << xv[j].b << ")";
  }
}
// struct确实好，多重排序用这个，可解决数组单一性解决不了的问题，