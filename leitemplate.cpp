#include <iostream>
using namespace std;
template <class T>
struct student {
  T math;
  // student() {};
  student(T x = 0) : math(x) {};
  friend ostream& operator<<(ostream& out, const student<T>& david) {
    out << david.math;
    return out;
  }
};
template <typename x, typename y>
class test {
  x a1;
  y a2;

 public:
  test(x a1, y a2) {
    this->a1 = a1;
    this->a2 = a2;
  }
  void print();
};
template <typename x, typename y>
void test<x, y>::print() {
  cout << this->a1 << endl << this->a2 << ' ' << endl;
}
int main() {
  // ming.math = 99;
  test<string, student<double>> aaa("hello", student<double>(99.9));
  aaa.print();

  // test<string, double> *b = new test<string, double>("hi", 18.8);
  // b->print(6.987);
  // aaa.print(968);
}

// template <class T>
// T getabs(T a) {
//   return abs(a);
// }
// int main() {
//   int a = 1;
//   float b = -2.3;
//   double c = -6.7;
//   string d = "123";
//   cout << getabs(a) << endl << getabs(b) << endl << abs(c);
// }