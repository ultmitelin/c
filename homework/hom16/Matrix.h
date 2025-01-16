#ifndef MAT_H
#define MAT_H
#include <iomanip>
#include <sstream>
using namespace std;
class matrix {
  int *m;
  int row, col;

 public:
  matrix(int r = 0, int c = 0) {
    m = new int[r * c];
    row = r;
    col = c;
    for (int i = 0; i < r * c; m[i] = i, i++);
  }

  ~matrix() { delete[] m; }
  struct MatrixException : public std::exception {
    const char *errstatus;

    MatrixException(const char *);
    const char *what() const noexcept;
  };
  int &operator()(int i, int j);
  friend ostream &operator<<(ostream &out, matrix &b);

  int getrow(matrix b) { return b.row; }
  int getcoloum(matrix b) { return b.col; }
  matrix operator+(matrix &y);
  inline matrix &operator*=(const int Cnum);
};

#endif