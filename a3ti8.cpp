#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int paishu;
    cin >> paishu;
    int sum;
    int au = 0, ag = 0, cu = 0;
    for (int j = 0; j < paishu; j++) {
      string s;
      cin >> s;
      if (s == "Au") {
        au++;
      }
      if (s == "Fe") {
        continue;
      }
      if (s == "Ag") {
        ag++;
      }
      if (s == "Cu") {
        cu++;
      }
    }

    int au1 = ag > cu ? cu : ag;
    sum = au + au1;
    // cout << au << endl << au1 << endl;
    cout << sum;
  }
}