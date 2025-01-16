#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
  double a, b, c, asin;
  scanf("%lf %lf", &a, &b);
  c = sqrt(a * a + b * b);
  asin = a / c;

  printf("%.3f\n", asin);
  cout << fixed << setprecision(4) << asin;
}
