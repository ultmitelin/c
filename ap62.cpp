// 调了很多次，deque加queue，很好
// 别局限于上课教的那点，数据结构是一个体系
// 灵活取用，别犹豫，别局限

#include <iostream>
#include <queue>
// 用dequeue试试
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<string> zu, zu1;
  queue<string> temp;

  for (int i = 0; i < t; i++) {
    char G;
    cin >> G;
    string s;
    cin >> s;
    if (G == 'A') {
      zu.push_back(s);
      for (int i = 0; i < zu.size(); i++) {
        cout << zu[i] << ' ';
      }
      cout << endl;
    } else {
      if (zu.empty()) {
        cout << "EMPTY" << endl;
      } else if (zu.size() == 1) {
        cout << "EMPTY" << endl;
        zu.erase(zu.begin());
      } else {
        // auto it = find(zu.begin(), zu.end(), s);
        // zu.erase(it);
        while (!zu.empty() && zu.back() != s) {
          temp.push(zu.back());
          zu.pop_back();
        }
        zu.pop_back();
        while (!temp.empty()) {
          zu.push_back(temp.front());
          temp.pop();
          /* code */
        }
        for (int i = 0; i < zu.size(); i++) {
          cout << zu[i] << ' ';
        }

        cout << endl;
      }
    }
  }
}

// #include <iostream>
// #include <queue>
// // 用dequeue试试
// #include <deque>
// #include <stack>
// using namespace std;
// int main() {
//   int t;
//   cin >> t;
//   deque<string> zu, zu1;
//   queue<string> temp;

//   for (int i = 0; i < t; i++) {
//     char G;
//     cin >> G;
//     string s;
//     cin >> s;
//     if (G == 'A') {
//       zu.push_back(s);
//       for (int i = 0; i < zu.size(); i++) {
//         cout << zu[i] << ' ';
//       }
//       cout << endl;
//     } else {
//       if (zu.empty()) {
//         cout << "EMPTY" << endl;
//       } else if (zu.size() == 1) {
//         cout << "EMPTY" << endl;
//         zu.pop_front();
//       } else {
//         while (!zu.empty() && zu.back() != s) {
//           temp.push(zu.back());
//           zu.pop_back();
//         }
//         zu.pop_back();
//         while (!temp.empty()) {
//           zu.push_back(temp.front());
//           temp.pop();
//           /* code */
//         }
//         for (int i = 0; i < zu.size(); i++) {
//           cout << zu[i] << ' ';
//         }

//         cout << endl;
//       }
//     }
//   }
// }

// #include <iostream>
// #include <stack>
// using namespace std;
// int main() {
//   stack<string> zu;
//   stack<string> temp;
//   stack<string> temp1;
//   int t;
//   cin >> t;
//   for (int i = 0; i < t; i++) {
//     char op;
//     cin >> op;
//     string x;
//     cin >> x;
//     if (op == 'A') {
//       zu.push(x);
//       while (!zu.empty()) {
//         temp.push(zu.top());
//         zu.pop();
//       }
//       while (!temp.empty()) {
//         cout << temp.top() << ' ';
//         zu.push(temp.top());
//         temp.pop();
//       }
//       cout << endl;
//     } else {
//       if (zu.empty() || zu.size() == 1) {
//         cout << "EMPTY" << endl;
//         if (zu.size() == 1) {
//           zu.pop();
//         }
//         continue;
//       }
//       while (zu.top() != x) {
//         temp.push(zu.top());
//         zu.pop();
//       }
//       zu.pop();
//       while (!temp.empty()) {
//         temp1.push(temp.top());
//         temp.pop();
//       }
//       while (!temp1.empty()) {
//         // cout<<temp1.top()<<' ';
//         zu.push(temp1.top());
//         temp1.pop();
//       }
//       while (!zu.empty()) {
//         temp.push(zu.top());
//         zu.pop();
//       }
//       while (!temp.empty()) {
//         cout << temp.top() << ' ';
//         zu.push(temp.top());
//         temp.pop();
//       }
//       cout << endl;
//     }
//   }
// }

// #include <iostream>
// #include <queue>
// // 用dequeue试试
// #include <stack>
// using namespace std;
// int main() {
//   int t;
//   cin >> t;
//   stack<string> zu, zu1;
//   queue<string> temp;

//   for (int i = 0; i < t; i++) {
//     char G;
//     cin >> G;
//     string s;
//     cin >> s;
//     if (G == 'A') {
//       zu.push(s);
//       while (!zu.empty()) {
//         zu1.push(zu.top());
//         zu.pop();
//         /* code */
//       }
//       while (!zu1.empty()) {
//         cout << zu1.top() << ' ';
//         zu.push(zu1.top());
//         zu1.pop();

//         /* code */
//       }
//       cout << endl;
//     } else {
//       if (zu.empty()) {
//         cout << "EMPTY" << endl;
//       } else if (zu.size() == 1) {
//         cout << "EMPTY" << endl;
//         zu.pop();
//       } else {
//         while (!zu.empty() && zu.top() != s) {
//           temp.push(zu.top());
//           zu.pop();
//         }
//         zu.pop();
//         while (!temp.empty()) {
//           zu.push(temp.front());
//           temp.pop();
//           /* code */
//         }
//         while (!zu.empty()) {
//           zu1.push(zu.top());
//           zu.pop();
//           /* code */
//         }
//         while (!zu1.empty()) {
//           cout << zu1.top() << ' ';
//           zu.push(zu1.top());
//           zu1.pop();

//           /* code */
//         }
//         cout << endl;
//       }
//     }
//   }
// }