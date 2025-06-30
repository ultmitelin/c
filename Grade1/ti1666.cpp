#include <iostream>
using namespace std;
int main() {
  long long a1, a2, b1, b2, c1, c2;
  cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
  long long sum = 0;
  for (long long i = a1; i <= a2; i++) {
    for (long long j = b1; j <= b2; j++) {
      long long max = i + j - 1;
      long long min = abs(i - j) + 1;
      max = max > c2 ? c2 : max;
      min = min < c1 ? c1 : min;
      if (min <= max)
        sum = sum + max - min + 1;  // 要加判断条件，否则没有三角形；
      // 取交集，求个数，不乱，想清楚，清晰；
      // 一开始想的是判断后用计数器一个一个加，他这种思路就很好了，在一个范围里就加减求出就对了；
      // 慢点，要深刻理解题意
      // 还是做的太少
      // 多练吧
    }
  }
  cout << sum;
}