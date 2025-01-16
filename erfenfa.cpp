#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
  long double n, low, high, mid;
  cin >> n;
  if (n == 0)
  {
    cout << 0 << endl;
    return 0;
  }
  low = 0;
  high = 4e4;
  mid = (low + high) / 2;
  while (fabs(mid * mid - n) > eps)
  {
    if (mid * mid - n > 0)
      high = mid;
    else
      low = mid;
    mid = low + (high - low) / 2;
  }
  cout << fixed;
  cout.precision(8);
  cout << mid << endl;
  return 0;
}