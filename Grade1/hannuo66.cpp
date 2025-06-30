#include <iostream>
using namespace std;
void hanoi(int n, char f, char a, char t) {
  if (n == 1) {
    cout << "move " << n << " from " << f << " to " << t << endl;
    return;
  } else {
    hanoi(n - 1, f, t, a);
    cout << "move " << n << " from " << f << " to " << t << endl;
  }
  hanoi(n - 1, a, f, t);
}
// 神奇，先搞好前几个，当它能运行去写

int main() {
  char From = '1';
  char assit = '2';
  char to = '3';
  int n;
  cin >> n;
  hanoi(n, From, assit, to);
}