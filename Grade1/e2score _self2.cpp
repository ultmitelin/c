// 这个题关键就在读取元素位置的确定，你要理解透那种不一样的计位方式

// ones这个vector太高了，大小存的1的个数，每个元素表示1在该字符串中（从0开始记）[自己修改后更易懂点】的位置。
// 它计位方式让人难受，那就用点手段改回来
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int qiu(int a);
string to_s(int a) {
  string s;
  for (; a; s = to_string(a & 1) + s, a = a >> 1);
  return s;
}
// int to_i(string s) {
//   int shu = 0;
//   for (int i = s.length() - 1; i >= 0; i--) {
//     shu = stoi(s.substr(i, 1), NULL, 10) * pow(2, s.length() - 1 - i) +
//     shu;//shu=shu*2+s[i]-'0'; cout << shu << endl;
//   }
//   return shu;
// }
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a;
    cin >> a;
    cout << qiu(a) << endl;
    // cout<<qiu(a);
  }
}
int qiu(int a) {
  if (a < 2) return a;
  string s = to_s(a);
  vector<int> ones;
  ones.push_back(0);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
      ones.push_back(i);
    }
  }
  // 这次求的是哪一位，有没有越界，必须清晰。
  int half = (ones.size() - 1) / 2;
  if ((ones.size() - 1) % 2 == 0) {
    return a + qiu(stoi(s.substr(0, ones[half] + 1), NULL, 2)) +
           qiu(stoi(s.substr(ones[half + 1]), NULL, 2));
  } else {
    if (ones.size() - 1 == 1) return a + 1;
    return a + qiu(stoi(s.substr(0, ones[half + 1] - 1 + 1), NULL, 2)) + 1 +
           qiu(stoi(s.substr(ones[half + 2]), NULL, 2));
  }
}