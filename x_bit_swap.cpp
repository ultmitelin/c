#include <iostream>
using namespace std;

int main()
{
  // i/o
  int x, i, j;
  cin >> x >> i >> j;

  // get x_i, x_j;
  int x_i = (x >> i) & 1, x_j = (x >> j) & 1;

  // compare
  if (x_i != x_j)
  {
    x ^= (1 << i);
    x ^= (1 << j);
  }

  // i/o
  cout << x << endl;

  return 0;
}