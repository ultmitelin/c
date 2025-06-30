#include <iostream>
#include <cmath>
using namespace std;

int zhuan(string str);
int main()
{
  char a;
  string s1, s2;
  int a1, a2, zhi;
  cin >> a;
  cin >> s1 >> s2;
  a1 = zhuan(s1);

  a2 = zhuan(s2);
  // cout << a1 << endl
  //    << a2 << endl;
  switch (a)
  {
  case '+':
    zhi = a1 + a2;
    zhi = fabs(zhi);
    cout << zhi << endl;
    break;
  case '-':
    zhi = a1 - a2;
    zhi = fabs(zhi);
    cout << zhi << endl;
    break;
  case '*':
    zhi = a1 * a2;
    zhi = fabs(zhi);
    cout << zhi << endl;
    break;
  case '/':
    if (a == '/' && a2 == 0)
    {
      cout << "Divided by zero!" << endl;
      break;
    }
    else
    {
      zhi = a1 / a2;
      zhi = fabs(zhi);
      cout << zhi << endl;
    }
    break;
  }
}
int zhuan(string str)
{
  string b1, c1, c2;
  int n = 6;
  b1 = str.substr(0, 2);
  c1 = str.substr(0, 1);
  c2 = str.substr(1, 1);
  if (b1 == "0b" || b1 == "0B")
  {
    n = stoi(str.substr(2), nullptr, 2);
  }

  else if (b1 == "0x" || b1 == "0X")
  {
    n = stoi(str.substr(2), nullptr, 16);
  }
  if (c1 == "0")
  {
    if (c2 != "b" && c2 != "B" && c2 != "x" && c2 != "X")
    {
      n = stoi(str.substr(1), nullptr, 8);
    }
  }
  if (c1 != "0")
  {
    n = stoi(str, nullptr);
  }
  return n;
}