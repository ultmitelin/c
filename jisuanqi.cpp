#include <math.h>

#include <iostream>
using namespace std;
int main() {
  int a, b;
  char hao;
  cin >> a >> b >> hao;
  switch (hao) {
    case '+':
      cout << a + b;
      break;

    case '-':
      cout << a - b;
      break;
    case '*':
      cout << a * b;
      break;
    case '/':
      if (b == 0) {
        cout << "除数不能为0.";
      } else
        cout << a / b;
      break;
    case '%':
      if (b == 0) {
        cout << "除数不能为0.";
      } else
        cout << a % b;
      break;
    default:
      cout << "字符不合法。";
      break;
  }
}