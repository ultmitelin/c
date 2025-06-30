#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;
int main() {
  stack<string> a;
  stack<double> a1;
  string line;
  getline(cin, line);
  stringstream s(line);
  string token;
  while (s >> token) {
    a.push(token);
  }
  // double op1, op2;
  while (!a.empty()) {
    // if (a.top() != "+" || a.top() != "-" || a.top() != "*" || a.top() != "/")
    // 一开始的判断，完全错误，没考虑好，不对，要记好正确形式
    // if (isdigit(a.top()[0]))
    // ai给的，没考虑到负数的情况，不好
    if (!(a.top() == "+" || a.top() == "-" || a.top() == "*" ||
          a.top() == "/")) {
      a1.push(stod(a.top()));
      // cout << "压入" << a.top() << endl;
      a.pop();

    } else {
      string x = a.top();
      double op1 = double(a1.top());
      // cout << "弹出" << a1.top() << endl;
      a1.pop();
      double op2 = double(a1.top());
      // cout << "弹出" << a1.top() << endl;
      a1.pop();
      switch (x[0]) {
        case '+':
          a1.push(op1 + op2);
          break;
        case '-':
          a1.push(op1 - op2);
          break;
        case '*':
          a1.push(op1 * op2);
          break;
        case '/':
          a1.push(op1 / op2);
          break;
      }
      a.pop();
    }
  }
  cout << fixed << a1.top();
}
