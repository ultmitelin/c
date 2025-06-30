#include <iostream>
using namespace std;
int main()
{
  int le;
  cin >> le;
  long long a1, p1;
  cin >> a1 >> p1;
  long long ma = a1, mp = p1;
  int id;
  for (int i = 2; i <= le; i++)
  {
    cin >> a1 >> p1;
    if (a1 * mp - ma * p1 < 0)
    {
      ma = a1;
      mp = p1;
      id = i;
    }
  }
  cout << id << endl;
  cout << fixed;
  cout.precision(12);
  cout << (long double)ma / mp << endl;
}
