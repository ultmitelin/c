// 一开始还想着给了s1，s2就不用给了，
// 还是太单纯了，单个字符的情况，就不能用之前的处理办法了，
// 必须要找到s1+s2才行，后面str相加的时候也要用find（s1+s2）的返回值
// ok
#include <iostream>
#include <string>
using namespace std;
int main() {
  string line;
  cin >> line;
  int t;
  cin >> t;
  // cout << line.substr(3, 5);
  // cout << line.find("wor");
  for (int i = 0; i < t; i++) {
    int l, r;
    cin >> l >> r;
    string s1, s2;
    string cut = line.substr(l - 1, r - l + 1);
    line = line.substr(0, l - 1) + line.substr(r);
    // cout << line << endl;
    cin >> s1 >> s2;
    // cout<<line.find(s1)+s1.length()<<endl<<line.find(s2)<<endl;;
    // cout << cut;
    if (line.find(s1) != string::npos && line.find(s2) != string::npos &&
        line.find(s1 + s2) != string::npos
        // ((line.find(s1) + s1.length() == line.find(s2)) ||
        //  (line.substr(line.find(s2) - s1.length(), s1.length()) == s1))
    ) {
      line = line.substr(0, line.find(s1 + s2) + s1.length()) + cut +
             line.substr(line.find(s1 + s2) + s1.length());
    } else {
      line = line + cut;
    }
    cout << line << endl;
  }

  cout << line << endl;
}