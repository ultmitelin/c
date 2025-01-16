#include <iostream>

#include "comp.cpp"
int main() {
  complex a2(3, 3.5);
  complex a3(9, 8);
  a2.add(a3);
  a2.show();
}