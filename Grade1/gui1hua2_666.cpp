
// 数据类型也有影响，一开始全定义了int类型结果不正确，改了double才过
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
  int n;
  double a;
  cin >> n;
  double zu1[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    zu1[i] = a;
  }
  double xmax1, xmin1;
  double zu[n], zu2[n];
  for (int i = 0; i < n; i++)
  {
    cout << zu2[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    zu[i] = zu1[i];
  }

  sort(zu, zu + n);
  xmax1 = zu[n - 1];
  xmin1 = zu[0];

  double xi[n];
  for (int i = 0; i < n; i++)
  {
    xi[i] = (zu1[i] - xmin1) / (xmax1 - xmin1);
    cout << fixed;
    cout.precision(15);
    cout
        << xi[i];
    cout << ' ';
  }
}
