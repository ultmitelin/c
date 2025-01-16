#include <iostream>
#include <bitset>
using namespace std;
int main()
{
  int x;
  cin >> x;

  int prod = 0;
  while (x)
  {
    prod <<= 1;
    prod |= x & 1;
    x >>= 1;
    bitset<sizeof(int) * 8> bit;
    bit = bitset<sizeof(int) * 8>(prod);
    cout << bit << endl;
  }

  cout << prod << endl;

  return 0;
}