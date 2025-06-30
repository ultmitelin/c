#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  vector<long long> dp(n + 1, 0);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += abs(A[i - 1]);
    dp[i] = max(dp[i - 1] + A[i - 1], sum);
  }

  long long result = 0;
  for (int i = 1; i <= n; i++) {
    result += dp[i];
  }

  cout << result << endl;
  return 0;
}