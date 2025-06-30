#include <exception>
#include <iostream>

// 自定义异常类
class CustomException : public std::runtime_error {
 public:
  CustomException(const char* s) : std::runtime_error(s) {}
};
int divide(int num1, int num2);
int main() {
  try {
    // 模拟可能会失败的操作，这里故意除以0
    int result = divide(10, 0);
    std::cout << "Result: " << result << std::endl;
  } catch (CustomException& e) {  // 捕获自定义的CustomException
    std::cerr << "Caught a custom exception: " << e.what() << '\n';
  } catch (std::exception& e) {  // 捕获所有标准异常
    std::cerr << "Caught a standard exception: " << e.what() << '\n';
  } catch (...) {  // 捕获所有未匹配的异常
    std::cerr << "Caught an unknown exception\n";
  }

  return 0;
}

// 定义可能会抛出异常的函数
int divide(int num1, int num2) {
  if (num2 == 0)
    throw CustomException("Division by zero is not allowed");  // 抛出异常
  return num1 / num2;
}
/*#include <iostream>
using namespace std;
int divid(int x, int y) {
  string c = "y==0";
  if (y == 0) throw c;
  return x / y;
}
int main() {
  try {
    int x, y;
    cin >> x >> y;
    cout << divid(x, y);
  } catch (string a) {
    cerr << "Error:" << a;
  }
}*/