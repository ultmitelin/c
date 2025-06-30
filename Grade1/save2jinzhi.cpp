#include <iostream>
using namespace std;
int main() {
  int x, a[50], wei = 0;
  cin >> x;
  for (; x; a[wei++] = x & 1, x = x >> 1);
  for (int i = --wei; i >= 0; i--) {
    cout << a[i];
  }
}