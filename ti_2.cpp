#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include <vector>
string pan(vector<int> zu, int a, int sum) {
  if (sum % 4 != 0) {
    return "no";
  }
  if ((zu[2] == 0 && zu[1] != 0) || (zu[a - 3] == 0 && zu[a - 2] != 0)) {
    return "no";
  }
  if ((zu[0] != 0 && (zu[1] - zu[0]) < 1) ||
      (zu[a - 1] != 0 && (zu[a - 2] - zu[a - 1]) < 1)) {
    return "no";
  }

  zu[1] = zu[1] - 2 * zu[0];
  zu[2] -= zu[0];
  zu[0] = 0;
  zu[a - 2] -= 2 * zu[a - 1];
  zu[a - 3] -= zu[a - 1];
  zu[a - 1] = 0;
  if ((zu[2] == 0 && zu[1] != 0) || (zu[a - 3] == 0 && zu[a - 2] != 0)) {
    return "no";
  }
  if ((zu[0] != 0 && (zu[1] - zu[0]) < 1) ||
      (zu[a - 1] != 0 && (zu[a - 2] - zu[a - 1]) < 1)) {
    return "no";
  }

  for (int i = 0; i < a; i++) {
    if ((zu[i] > 2 * zu[i + 1]) && (zu[i] > 2 * zu[i - 1])) {
      return "no";
    }
  }

  return "yes";
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a;
    cin >> a;
    vector<int> zu(a);
    int sum = 0;
    for (int j = 0; j < a; cin >> zu[j], sum += zu[j], j++);
    cout << pan(zu, a, sum) << endl;
  }
  return 0;
}