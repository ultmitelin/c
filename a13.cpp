#include <iostream>
int main() {
#if __cplusplus == 201703L
  std::cout << "✅ C++17 已启用 (__cplusplus=" << __cplusplus << ")\n";
#else
  std::cout << "❌ 当前标准: " << __cplusplus << "（不是 C++17）\n";
#endif
  return 0;
}
