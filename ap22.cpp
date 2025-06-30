#include <iostream>
#include <stack>
using namespace std;
int main() {
  stack<int> in;
  stack<int> out;
  int t;
  cin >> t;
  string s;
  for (int i = 0; i < t; i++) {
    cin >> s;

    if (s == "push") {
      int x;
      cin >> x;
      in.push(x);
    } else if (s == "pop") {
      if (!out.empty()) {
        out.pop();
        continue;
      }
      while (!in.empty()) {
        out.push(in.top());
        in.pop();
      }
      out.pop();
    } else if (s == "query") {
      int j;
      cin >> j;
      if (j == 1) {
        if (out.empty()) {
          while (!in.empty()) {
            out.push(in.top());
            in.pop();
            /* code */
          }
        }
        cout << out.top() << endl;
      } else {
        int x = in.size();
        int y = out.size();
        int z = x > y ? y : x;
        int z1 = x > y ? x : y;
        cout << z << ' ' << z1 << endl;
      }
    }
  }
}