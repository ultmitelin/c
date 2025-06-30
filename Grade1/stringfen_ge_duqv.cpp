// #include <cstring>
#include <iostream>
using namespace std;
#include <sstream>  // 需要用到istringstream来分割字符串

int main() {
  std::string input = "10245102413 100 99";  // 输入字符串
  string studentId;
  int chineseScore, mathScore;

  // 使用istringstream将字符串分割成三个部分
  std::istringstream iss(input);
  // (iss >> studentId >> chineseScore >> mathScore);
  if (!(iss >> studentId >> chineseScore >> mathScore)) {  //
    // 检查能否成功读取
    std::cerr << "Invalid input format" << std::endl;
  }

  // 存储数据
  std::cout << "Student ID: " << studentId << std::endl;
  std::cout << "Chinese Score: " << chineseScore << std::endl;
  std::cout << "Math Score: " << mathScore << std::endl;

  return 0;
}