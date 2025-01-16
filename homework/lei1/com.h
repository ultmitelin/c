#ifndef COM_H
#define COM_H
#endif
class complex {
  double real;
  double image;

 public:
  complex(double, double a = 0);
  void add(const complex&);
  void show();
};
