// 简单易行就好，先别搞那么多花的 要清晰
#include <iostream>
#include <cmath>

using namespace std;
bool isPrime(int num)
{
  if (num <= 1)
  {
    // 0和1不是质数
    return false;
  }
  for (int i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  return true;
}
int main()
{
  int m, n;
  cin >> m >> n;
  int a = m + 1, ci = 0;
  while (ci < n)
  {
    if (isPrime(a))
    {
      ci++;
    }
    a++;
  }
  a--;
  cout << a;
}