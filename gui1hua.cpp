
/*
别急
大化小
化繁为简
一步一步
总会到的
一口吃不成胖子
一步跨不到天边
*/
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
  int n;
  double xmax, xmin, a;
  cin >> n;
  int zu[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    zu[i] = a;
  }
  double xmax1, xmin1;

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      xmax = zu[i];
    }
    else if (zu[i] > xmax)
    {
      xmax = zu[i];
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      xmin = zu[i];
    }
    else if (zu[i] < xmin)
    {
      xmin = zu[i];
    }
  }
  sort(zu, zu + n);
  xmax1 = zu[n - 1];
  xmin1 = zu[0];
  cout << xmax << ' ' << xmin << endl;
  cout << xmax1 << ' ' << xmin1 << endl;

  double xi[n];
  for (int i = 0; i < n; i++)
  {
    xi[i] = (zu[i] - xmin) / (xmax - xmin);
    cout << fixed;
    cout.precision(15);
    cout
        << xi[i];
    cout << ' ';
  }
}