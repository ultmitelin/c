#include <algorithm>
#include <iostream>
#include <numbers>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int arr[5];
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + 5);
  int shu = arr[0];
  int x = arr[0];
  for (int i = 0; i < 4; i++) {
    x = gcd(x, arr[i + 1]);
  }
  cout << x << endl;
  while (true) {
    int x = 0;
    for (int i = 0; i < 5; i++) {
      if (arr[i] % shu != 0) {
        x = 1;
      }
    }
    if (x == 0) {
      cout << shu;
      break;
    }
    shu--;
  }

  return 0;
}