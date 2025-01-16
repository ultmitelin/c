#include <iostream>
using namespace std;

int main()
{
  unsigned x, n, as = 0;
  std::cin >> x >> n;
  // n %= 32;
  as = (x << (32 - n) % 32) | x >> n;
  std::cout << as << std::endl;

  return 0;
}