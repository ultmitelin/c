#include <math.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
using namespace std;
int main() {
  int a;
  string s;
  cin >> a >> s;
  // reverse(s.begin(), s.end());
  // cout << s << endl;
  stringstream ss(s);
  char x;
  int result = 0;
  bool zf = 1;
  bool xiao = 0;
  while (ss >> x) {
    if (x == '-') {
      zf = 0;
      continue;
    }
    if (x == '.') {
      xiao = 1;
      break;
    }
    // cout << x << ' ';
    if (x >= '0' && x <= '9') {
      result = result * a + x - '0';
    } else if (x >= 'a' && x <= 'z') {
      result = result * a + x - 'a' + 10;
    } else if (x >= 'A' && x <= 'Z') {
      result = result * a + x - 'A' + 10;
    }
  }
  if (result != 0) {
    if (!zf) {
      cout << '-';
      zf = 1;
    }
    cout << result << ' ';
  }
  if (!xiao) {
    return 0;
  }
  int wei = 0;
  int result1 = 0;

  while (ss >> x) {
    // cout << x << ' ';
    if (x >= '0' && x <= '9') {
      result1 = result1 * a + x - '0';
    } else if (x >= 'a' && x <= 'z') {
      result1 = result1 * a + x - 'a' + 10;
    } else if (x >= 'A' && x <= 'Z') {
      result1 = result1 * a + x - 'A' + 10;
    }
    wei++;
  }
  wei++;
  wei--;
  // ok wei不用再++
  int mu = pow(a, wei);
  int in = __gcd(result1, mu);
  result1 /= in;
  mu /= in;
  if (!zf) {
    cout << '-';
  }
  cout << result1 << ' ' << mu;
}