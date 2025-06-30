#ifndef COM_CPP
#define COM_CPP
#include "com.h"
#endif
#include <iostream>
using namespace std;
complex::complex(double a, double b) {
  this->real = a;
  this->image = b;
}
void complex::add(const complex& a) {
  this->real += a.real;
  this->image += a.image;
}
void complex::show() { cout << real << '+' << image << 'i' << endl; }