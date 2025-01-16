#include <iostream>
#include <string>

#include "Queue.cpp"
#include "Queue.h"
using namespace std;
int main() {
  Queue rq{5};  // with capacity 100002
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    try {
      string cmd;
      cin >> cmd;
      if (cmd == "e") {
        int data;
        cin >> data;
        rq.enqueue(data);
        // rq.show();
        cout << endl;
      } else if (cmd == "d") {
        cout << rq.dequeue() << endl;
        // rq.show();
        cout << endl;
      }
    } catch (string s1)  // enqueue on/ full, dequeue on empty
    {
      cout << s1 << endl;
    }
  }
  return 0;
}