#include <algorithm>
#include <iostream>
using namespace std;
#include <vector>
bool cmp(vector<int> a, vector<int> b) {
  int len;
  if (a.size() < b.size())
    len = a.size();
  else
    len = b.size();
  for (int i = 0; i < len; i++) {
    if (a[i] > b[i])
      return true;
    else if (a[i] < b[i])
      return false;
  }
  if (a.size() > b.size())
    return true;
  else
    return false;

  // int i = 0;
  // if (a.  [i] == b.  [i])
  //   return a.  [++i] < b.  [++i];
  // else
  //   return a.  [i] < b.  [i];
}
int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int pp, x;
    vector<int> zu[1000];
    cin >> pp;
    for (int j = 0; j < pp; j++) {
      for (cin >> x; x != -1; cin >> x) zu[j].push_back(x);
    }
    sort(zu, zu + pp, cmp);
    for (int j = 0; j < pp; j++) {
      for (int i = 0; i < (int)zu[j].size(); i++) {
        cout << zu[j][i] << ' ';
      }
      cout << endl;
    }
  }
}