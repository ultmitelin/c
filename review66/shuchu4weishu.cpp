
#include <iomanip>
#include <iostream>

int main() {
  int number = 5;  // 假设我们有一个数字5
  std::cout << std::hex << number;
  std::cout << std::setfill('0') << std::setw(4) << number
            << std::endl;  // 输出：0005

  return 0;
}