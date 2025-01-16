// cout << hex << uppercase << setfill('0') << setw(4) << b;
//  把整数b以4位大写16进制形式输出
// 问ai问题要精准明确问到细节处，要读懂他写的，英文单词不懂的就去查，不够简洁就让他简洁再来一次
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int n, t;
  cin >> n;
  int zu[n];
  for (int i = 0; i < n; i++) {
    cin >> zu[i];
  }
  cin >> t;
  int flag = 0, a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (zu[i] == t) {
      a = i;
      flag = 1;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (zu[i] == t) {
      b = i;
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    cout << "FFFFFFFF";
  } else if (a != 0) {
    cout << hex << uppercase << a;
    cout << hex << uppercase << setfill('0') << setw(4) << b;
  } else {
    cout << hex << uppercase << b;
  }
}