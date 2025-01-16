#include <iostream>
using namespace std;
int main()
{
  short zu[32] = {0};
  int i, n;
  cin >> n;
  for (i = 0; i < 32; i++)
  {
    zu[i] = n % 2;
    n = n / 2;
    if (n == 0)
    {
      break;
    }
  }
  for (n = 0; i >= 0; i--)
  {
    cout << i << endl;
    cout << zu[i] << endl;
  }
}