#ifndef COMPLEX_H_INCLUDED
#include "MyComplex.h"
#define COMPLEX_H_INCLUDED
#endif

#include <iostream>

inline Complex::Complex(double real, double imag) {
  this->real = real;
  this->imag = imag;
}

inline void Complex::add(const Complex& b) {
  this->real += b.real;
  this->imag += b.imag;
}

inline void Complex::show() const {
  std::cout << this->real << '+' << this->imag << 'i' << '\n';
}
