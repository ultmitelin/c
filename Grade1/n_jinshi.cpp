#include <algorithm>  // 用于std::reverse
#include <iostream>
#include <string>
using namespace std;
void itob(int n, std::string &s, int b) {
  // // 检查进制是否合法
  // if (b < 2 || b > 36) {
  //     std::cerr << "Invalid base. Base should be between 2 and 36." <<
  //     std::endl; return;
  // }

  // // 清空字符串

  // // 特殊情况：n为0
  // if (n == 0) {
  //     s += '0';
  //     return;
  // }

  // // 判断正负
  // bool isNegative = n < 0;
  // if (isNegative) {
  //     n = -n; // 转换为正数处理
  // }

  // // 进制转换
  // while (n > 0) {
  //     int remainder = n % b;
  //     char digit;

  //     // 将数字转换为字符
  //     if (remainder < 10) {
  //         digit = '0' + remainder;
  //     } else {
  //         digit = 'A' + (remainder - 10);
  //     }

  //     // 添加到字符串
  //     s += digit;
  //     n /= b;
  // }

  // // 如果是负数，添加负号
  // if (isNegative) {
  //     s += '-';
  // }

  // // 反转字符串，因为目前的顺序是反的
  // std::reverse(s.begin(), s.end());

  s.clear();  // 也可用s = "";

  if (n == 0) s = "0";

  bool judge = (n < 0);  // 这个负数处理法好；留标记两次判断

  if (judge) {
    n = -n;
  }
  while (n > 0) {
    int x = n % b;
    string s1 = "";
    if (x < 10)
      s1 = '0' + x;
    else {
      s1 = 'A' + x - 10;
    }
    s = s1 + s;
    n /= b;
  }
  if (judge) s = "-" + s;
}

// 测试代码
int main() {
  std::string result;
  itob(0, result, 16);  // 转换为16进制
  std::cout << "255 in base 16: " << result << std::endl;

  itob(900479765, result, 35);  // 负数转换为16进制
  std::cout << "-255 in base 16: " << result << std::endl;

  itob(-489968884, result, 18);  // 转换为2进制
  std::cout << "10 in base 2: " << result << std::endl;

  itob(-4, result, 3);  // 转换为8进制
  std::cout << "0 in base 8: " << result << std::endl;

  return 0;
}