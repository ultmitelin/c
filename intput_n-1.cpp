using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>

// 结构体，用于存储一行数字
struct NumberRow {
  std::vector<int> numbers;
};

// 函数，从标准输入读取一行数字，直到遇到-1为止
void inputNumbers(NumberRow& row) {
  int number;
  for (cin >> number; number != -1; cin >> number) {
    row.numbers.push_back(number);
  }
  // std::cin >> number;

  // // 循环读取，直到遇到-1
  // while (number != -1) {
  //   row.numbers.push_back(number);
  //   std::cin >> number;
  // }
}
bool cmp(NumberRow a, NumberRow b) {
  int len;
  if (a.numbers.size() < b.numbers.size())
    len = a.numbers.size();
  else
    len = b.numbers.size();
  for (int i = 0; i < len; i++) {
    if (a.numbers[i] > b.numbers[i])
      return true;
    else if (a.numbers[i] < b.numbers[i])
      return false;
  }
  if (a.numbers.size() > b.numbers.size())
    return true;
  else
    return false;

  // int i = 0;
  // if (a.numbers[i] == b.numbers[i])
  //   return a.numbers[++i] < b.numbers[++i];
  // else
  //   return a.numbers[i] < b.numbers[i];
}
int main() {
  NumberRow row[100];
  int T;
  cin >> T;
  for (int j = 0; j < T; j++) {
    int pp;
    cin >> pp;
    for (int i = 0; i < pp; i++) {
      inputNumbers(row[i]);
    }
    std::sort(row, row + pp, cmp);
    // 打印结构体中的数字
    for (int i = 0; i < pp; i++) {
      for (const auto& num : row[i].numbers) {
        std::cout << num << " ";
      }
      std::cout << "\n";  // 结束行
    }
  }
  return 0;
}