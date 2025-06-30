#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
  stack<char> a;
  char x;
  while ((x = getchar()) != EOF) {
    // if (!a.empty() && a.top() == '*') {
    //   if (x != '*') continue;
    // }
    if (x == '(' || x == '{' || x == '[' || x == '/') {
      if (x == '/') {
        x = getchar();
        if (x == '*') {
          a.push(x);
        }
      } else {
        a.push(x);
      }
      continue; /*是前半部分，入栈之后，就直接下一次，否则还会再判断‘*’ 就出错了
                 */
    }
    if (x == ')' || x == '}' || x == ']' || x == '*') {
      if (x == '*') {
        x = getchar();
        if (x == '/') {
          if (a.top() == '*') {
            // cout << "pop" << x << endl;
            a.pop();
          }
        }
      }
      if (x == ']') {
        if (a.top() == '[') {
          a.pop();
        }
      }
      if (x == '}') {
        if (a.top() == '{') {
          a.pop();
        }
      }
      if (x == ')') {
        if (a.top() == '(') {
          a.pop();
        }
      }
    }
  }

  /* else if (x == ']' && !a.empty() && a.top() == '[') {
     a.pop();
 } else if (x == '}' && !a.empty() && a.top() == '{') {
     a.pop();
 } else if (x == ')' && !a.empty() && a.top() == '(') {
     a.pop();
 } else {
     // 不匹配的括号
     cout << "NO";
     return 0;
 }*/
  //  AI的处理，确实更好

  //   3. 栈为空时访问 a.top()
  // 在检查匹配时，代码直接调用了
  // a.top()，但没有检查栈是否为空。如果栈为空时调用 a.top()，会导致运行时错误。
  if (a.empty()) {
    cout << "YES";
  } else
    cout << "NO";
}
