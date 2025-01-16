#include <algorithm>
#include <iostream>
using namespace std;
#include <vector>
int main() {
  int zushu, x;
  vector<int> zu[1000];
  cin >> zushu;
  for (int j = 0; j < zushu; j++) {
    for (cin >> x; x != -1; cin >> x) {
      zu[j].push_back(x);
    }
    sort(zu[j].begin(), zu[j].end());
    int sum = 0, av = 0;
    for (int k = 0; k < zu[j].size(); k++) {
      sum += zu[j][k];
    }
    av = sum / zu[j].size();
    cout << "case #" << j << ":" << endl;
    cout << zu[j][zu[j].size() - 1] << endl << zu[j][0] << endl << av << endl;
  }

  // for (int j = 0; j < zushu; j++) {
  //   for (int i = 0; i < (int)zu[j].size(); i++) {
  //     cout << zu[j][i] << ' ';
  //   }
  //   cout << endl;
  // }
}
