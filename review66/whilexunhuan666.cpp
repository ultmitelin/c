#include <iostream>
using namespace std;
int main()
{
  int i = 0, sum = 0;

  while (i <= 100)
  {
    sum = sum + i;
    cout << sum << endl;
    cout << "当前循环次数i=" << i << endl;
    i++;
  }
  cout << sum;
  return 0;
}