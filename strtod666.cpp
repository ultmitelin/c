#include <iostream>
#include <cstring>
using namespace std;
int main()
{

  char a[] = "123.45e-6";
  float b;
  b = strtod(a, NULL);
  cout << b;
}