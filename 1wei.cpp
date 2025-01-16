#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  int c;
  cin >> c;
  int ci = 0, i = 0, n = 0;
  while (i < 8) {
    n = (c >> i) & 1;
    if (n == 1) {
      ci++;
    }
    i++;
  }
  cout << ci << endl;
  return 0;
}