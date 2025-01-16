// 在上面的 C++ 代码中，当我们传递 `num1` 和 `num2` 到 `swapNumbers`
// 函数时，实际上我们是在传入的是这两个变量的引用（reference）。这是因为在 C++
// 中，函数参数默认是按值传递的，这意味着每次函数调用时，实际上是复制了实参的副本到形参。如果需要修改实参的值，就需要显式地传递其引用。

// `&` 取地址运算符在这里的作用就是获取变量 `num1` 和 `num2`
// 的内存地址，这样函数就能直接操作原始变量，而不仅仅是复制的副本。所以：

// ```cpp
// void swapNumbers(int& a, int& b) {
//     std::swap(a, b);  // 直接操作变量 a 和 b，不需要返回值
// }
// ```

// 当你在函数定义中看到 `int& a` 和 `int& b`，这意味着你正在提供对 `num1` 和
// `num2` 变量本身的访问，允许函数内部改变这些变量的值。

// 如果不加 `&`，如 `void swapNumbers(int a, int b)`，那么 `a` 和 `b`
// 就会成为独立的新变量副本，原始的 `num1` 和 `num2` 保持不变。
#include <iostream>
// 要加取地址符，否则函数执行完栈清空就没了，无效操作；
using namespace std;
void aba(int &a, int &b) { swap(a, b); }
// int abc(int a, int b) {
//   int c;
//   c = a;
//   a = b;
//   b = c;
//   return c;
// }
int main() {
  int a = 1, b = 2;
  int c = 3, d = 4;
  int x = 5, z = 6;
  // abc(c, d);

  aba(a, b);
  swap(x, z);
  // /  cout << abc(a, b) << endl;
  cout << a << ' ' << b;
  cout << endl << c << ' ' << d;
  cout << endl << x << ' ' << z;
}