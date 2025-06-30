#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long bin_s(vector<long long>& zu, long long goal, long long n) {
  long long l = 0, r = n;
  long long found = -1;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    if (zu[mid] == goal) {
      found = mid;
      break;
    } else if (zu[mid] < goal) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return found;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, q;
  cin >> n >> q;
  vector<long long> zu(n);
  for (long long i = 0; i < n; cin >> zu[i++]);
  while (q--) {
    long long goal;
    cin >> goal;
    cout << bin_s(zu, goal, n) << '\n';
    // auto it = find(zu.begin(), zu.end(), goal);
    // if (it != zu.end()) {
    //   cout << it - zu.begin() << endl;
    // } else {
    //   cout << -1 << '\n';
    // }
  }
}