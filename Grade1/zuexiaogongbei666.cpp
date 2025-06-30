#include <iostream>
using namespace std;
#define N 9
// 数字非常大时一个一个试不可行，会超时；
//  要想想简便算法，别急，思路清晰；考虑清所有情况；
long long LCM(int a[], int n) {
  // precondition: 1≤n≤9， 1≤a[i]≤100
  // postcondition: return LCM of all integers
  // precondition: 1≤n≤9， 1≤a[i]≤100
  // postcondition: return LCM of all integers

  long long arr[2] = {0};
  long long z = 0;
  arr[0] = a[0];
  arr[1] = a[1];

  for (int j = 2; j <= n; j++) {
    long long shu = arr[1];
    while (shu) {
      int x = 0;
      for (int i = 0; i < 2; i++) {
        if (arr[i] % shu != 0) {
          x = 1;
        }
      }
      if (x == 0) {
        z = shu;
        break;
      }
      shu--;
    }
    arr[0] = arr[0] / z * arr[1];

    if (j < n) {
      arr[1] = a[j];
    }
  }
  return arr[0];
}

int main() {
  int i, n, a[N];
  for (cin >> n, i = 0; i < n; i++) cin >> a[i];
  cout << LCM(a, n) << endl;
  return 0;
}
