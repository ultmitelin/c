#include <algorithm>
#include <iostream>
using namespace std;

bool cmpda(int a, int b) { return a > b; }
int main() {
  char order;
  cin >> order;
  int zu[1000];
  int i = 0;

  int a;
  while (cin >> a) {
    zu[i++] = a;
  }

  int len = i + 1;
  if (len == 0) cout << zu[0];
  for (int i = 0; i < len; i++) {
    // if (zu[i] == zu[i - 1]) i--;
    for (int j = i + 1; j < len; j++) {
      if (zu[j] == zu[i]) {
        for (int k = j; k < len - 1;
             k++) {  // 一开始没定义k，直接用j，结果把次数直接减了好多
          // 要确保for循环记录次数的变量不在for括号以外变化
          zu[k] = zu[k + 1];
        }
        len--;
        j--;
      }
    }
  }
  if (order == 'A') sort(zu, zu + len);
  if (order == 'D') sort(zu, zu + len, cmpda);

  for (int i = 0; i < len; cout << zu[i] << ' ', i++);
}