#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main()
{
  int n, a, m;
  cin >> a >> m;
  bitset<32> bit, hello;
  // 定义一个n位二进制数
  bit = bitset<32>(a);
  hello = bitset<32>(m);
  cout << bit << endl
       << hello << endl;

  string hello1;

  hello1 = to_string(m);
  n = stoi(hello1, nullptr, 16);
  cout << n << endl;

  return 0;
}