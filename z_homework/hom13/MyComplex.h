#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#endif

class Complex {
  double real;
  double imag;

 public:
  Complex(double, double = 0);
  void add(const Complex&);
  void show() const;
};
