#include <iostream>

#include "Complex.cpp"

int main() {
  Complex c1(3, 5.6);
  Complex c2 = 4.5;

  c1.add(c2);
  c1.show();

  return 0;
}