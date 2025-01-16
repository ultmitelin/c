#include <cmath>
#include <iostream>
using namespace std;
int main() {
  double l1, l2, d1, d2, l;  // 此处用int类型会丢精度
  // d2/d1，double类型更精准
  cin >> l1 >> d1 >> l2 >> d2 >> l;
  double q, d;
  q = exp(log(d2 / d1) / (l2 - l1));
  d = d1 * pow(q, (l - l1));
  cout << fixed;
  cout.precision(15);
  cout << d;
}