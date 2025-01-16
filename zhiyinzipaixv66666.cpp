#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
struct hhh {
  int x;
  int y;
};
bool cmp(hhh a, hhh b) {
  if (a.y != b.y) return a.y > b.y;
  return a.x > b.x;
}
int main() {
  int t;
  cin >> t;
  hhh zu[40011];
  vector<int> zhi;
  for (int i = 2; i <= 400; i++) {
    int flag = 1;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) zhi.push_back(i);
  }
  for (int i = 0; i < t; i++) {
    int a;
    cin >> a;
    zu[i].x = a;
    int shu = 0;
    for (int j = 0; zhi[j] * zhi[j] <= a; j++) {
      if (a % zhi[j] == 0) {
        shu++;
        while (a % zhi[j] == 0) {
          a /= zhi[j];
        }
      }
    }
    if (a > 1) shu++;
    zu[i].y = shu;
  }
  sort(zu, zu + t, cmp);
  // for (int i = 0; i < 20; cout << zhi[i] << endl, i++);
  for (int i = 0; i < t; i++) {
    cout << zu[i].x << ' ';
    // cout << endl;
    // cout << zu[i].y << ' ';
  }
}