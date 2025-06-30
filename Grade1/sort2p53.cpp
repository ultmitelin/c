#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(long long a, long long b) {
  unsigned long long highestDigit1 = 0;
  unsigned long long highestDigit2 = 0;
  if (a < 0) {
    highestDigit1 = -a;
    // while (highestDigit1 / 10 >= 1) {  // 取余操作，直到余数不是0
    //   highestDigit1 /= 10;
    // }
  } else {
    highestDigit1 = a;
    // while (highestDigit1 / 10 >= 1) {  // 取余操作，直到余数不是0
    //   highestDigit1 /= 10;
    // }
  }
  while (highestDigit1 / 10 >= 1) {  // 取余操作，直到余数不是0
    highestDigit1 /= 10;
  }
  if (b < 0) {
    highestDigit2 = -b;
    while (highestDigit2 / 10 >= 1) {  // 取余操作，直到余数不是0
      highestDigit2 /= 10;
    }
  } else {
    highestDigit2 = b;
    while (highestDigit2 / 10 >= 1) {  // 取余操作，直到余数不是0
      highestDigit2 /= 10;
    }
  }
  if (highestDigit1 != highestDigit2) {
    return highestDigit1 > highestDigit2;
  } else
    return a < b;
}
int main() {
  int t;
  cin >> t;
  long long zu[t]
              [1000];  // 元素个数定多一点（尽量满足要求），但不能太多（会超限）
  int nshu[t];
  for (int i = 0; i < t; i++) {
    int n = 0;
    cin >> n;
    nshu[i] = n;
    for (int j = 0; j < n; cin >> zu[i][j], j++);
  }
  for (int i = 0; i < t; i++) {
    cout << "case #" << i << ":" << endl;
    long long zu1[1000] = {0};
    for (int j = 0; j < nshu[i]; j++) {
      zu1[j] = zu[i][j];
    }
    sort(zu1, zu1 + nshu[i], cmp);
    for (int m = 0; m < nshu[i]; cout << zu1[m] << ' ', m++);
    cout << endl;
  }
  // for (int i = 0; i < t; i++) {
  //   for (int j = 0; j < nshu[i]; cout << zu[i][j] << ' ', j++);
  //   cout << endl;
  // }
}