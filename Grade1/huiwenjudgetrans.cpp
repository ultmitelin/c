#include <algorithm>
#include <iostream>
using namespace std;

int fan(int sum) {
  string a = to_string(sum);
  string b = a;
  reverse(b.begin(), b.end());
  int fannum = stoi(b, nullptr, 10);
  return fannum;
}
int judge(int sum) {
  int sum1 = fan(sum);
  if (sum == sum1)
    return 1;
  else
    return 0;
}
int main() {
  int num;
  cin >> num;
  int ci = 0, sum = num;
  while (1) {
    int flag = 0;
    int fannum = fan(sum);
    if (judge(sum) != 1) {
      sum = sum + fannum;
      ci++;
      flag = 1;
    }
    if (flag == 0) break;
  }
  cout << ci << ' ' << sum;
}