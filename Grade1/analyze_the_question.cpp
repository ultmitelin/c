// 本来下面那种就很简单能解决了，但前面自作多情以为没给定每行数字数，
// 要审题
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> zu[n + 1];

  string line;
  getline(cin, line);
  for (int i = 1; i <= n; i++) {
    int x;
    getline(cin, line);
    istringstream a(line);
    while (a >> x) {
      zu[i].push_back(x);
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = zu[i].size() - 1; j >= 0; j--) {
      cout << zu[i][j] << ' ';
    }
    cout << endl;
  }
}

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> zu[n + 1];

  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x;
    for (int j = 0; j < x; j++) {
      cin >> y;
      zu[i].push_back(y);
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = zu[i].size() - 1; j >= 0; j--) {
      cout << zu[i][j] << ' ';
    }
    cout << endl;
  }
}