#include <iostream>
#include <bitset>
using namespace std;

int main()
{
  int a;
  cin >> a;
  bitset<sizeof(int) * 8> bit;
  bit = bitset<sizeof(int) * 8>(a);
  cout << bit;
  return 0;
}