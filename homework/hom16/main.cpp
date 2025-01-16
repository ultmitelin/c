#include <iostream>

#include "Matrix.cpp"
#include "Matrix.h"
using namespace std;
int main() {
  matrix x(5, 5), y(5, 5);
  cout << x(3, 3) << endl;
  matrix z = x + y;
  cout << z;
}