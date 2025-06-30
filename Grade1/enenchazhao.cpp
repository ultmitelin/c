#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int zu[n] = {0};

  int bufu = -1;
  int low = 0, hi = n - 1;
  for (int m = 0; m < n; m++)
  {
    cin >> zu[m];
  }

  int mid, key;
  cin >> key;
  while (low <= hi)
  {
    mid = (low + hi) / 2;
    if (zu[mid] == key)
    {
      bufu = mid;
      break;
    }
    else if (zu[mid] < key)
      low = mid + 1;

    else

      hi = mid - 1;
  }
  if (bufu == -1)
    cout << "-1";
  else
    cout << bufu;
  return 0;
}