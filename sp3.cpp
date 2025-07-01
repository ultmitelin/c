#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int count_1_char(char c) {
  int ones = 0;
  for (int i = 0; i < 8; i++) {
    if (c & (1 << i)) {
      ones++;
    }
  }
  return ones;
}
int count_1_str(string s) {
  int ones = 0;
  for (auto c : s) {
    ones += count_1_char(c);
  }
  return ones;
}
void simplify(int a, int b) {
  int in = __gcd(a, b);
  cout << (a /= in) << '/' << (b /= in) << '\n';
}
int main() {
  int n;
  cin >> n;
  string line;
  getline(cin, line);
  for (int i = 0; i < n; i++) {
    getline(cin, line);
    int total_bits = line.size() * 8;
    int total_1s = count_1_str(line);
    simplify(total_1s, total_bits);
  }
}