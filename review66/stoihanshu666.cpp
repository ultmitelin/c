#include <iostream>
#include <string>
using namespace std;
int main()
{
  string as, my;
  int m, n;
  cin >> as >> my;
  m = stoi(as, nullptr, 16);
  n = stoi(my.substr(2), nullptr, 2);
  cout << m << endl
       << n;
}