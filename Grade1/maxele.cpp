#include <algorithm>
#include <iostream>

int main() {
  int arr[] = {5, 10, 1, 8, 3};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  // 使用 max_element 找到最大值
  auto max_val = *std::max_element(arr, arr + n);

  std::cout << "The maximum number in the array is: " << max_val << std::endl;

  return 0;
}