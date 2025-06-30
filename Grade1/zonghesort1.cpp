#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int high(int a) {
  if (a < 0) a = -a;
  while (a / 10 > 1) a = a / 10;
  return a;
}
bool cmp1(int a, int b) {
  if (high(a) != high(b))
    return high(a) > high(b);
  else
    return a < b;
};
bool cmp2(vector<int>& a, vector<int>& b) {
  if (a.size() != b.size()) return a.size() > b.size();
  return true;
};
using namespace std;
int main() {
  int r, c;
  cin >> r >> c;
  // vector<int> hang[r];
  vector<vector<int>> dp;
  vector<int> arr;
  int a;
  for (int j = 0; j < r; j++) {
    arr.resize(0);
    for (int i = 0; i < c; i++) {
      cin >> a;
      // hang[j].push_back(a);
      arr.push_back(a);
    }
    dp.push_back(arr);
  }
  sort(arr.begin(), arr.end(), cmp1);
  sort(dp.begin(), dp.end(), cmp2);
  for (int j = 0; j < r; j++) {
    for (int i = 0; i < c; i++) {
      cout << dp[j][i] << ' ';
    }
    cout << endl;
  }
}