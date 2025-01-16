#ifndef MAT_CPP
#define MAT_CPP
#include "Matrix.h"
int &matrix::operator()(int i = 0, int j = 0) { return this->m[i * col + j]; }
ostream &operator<<(ostream &out, matrix &b) {
  for (int i = 0; i < b.row; i++) {
    for (int j = 0; j < b.col; j++) {
      out << b(i, j) << ' ';
    }
    out << endl;
  }
  return out;
};
matrix matrix::operator+(matrix &y) {
  for (int i = 0; i < this->row; i++) {
    for (int j = 0; j < this->col; j++) {
      // this(i, j) = this(i, j) + y(i, j);
      this->m[i * col + j] = this->m[i * col + j] + y(i, j);
    }
  }
  return *this;
}
inline matrix &matrix::operator*=(const int Cnum) {
  for (int r = 0; r < row; ++r) {
    for (int c = 0; c < col; ++c) {
      matrix(r * col + c) *= Cnum;
    }
  }
  return *this;
}
#endif