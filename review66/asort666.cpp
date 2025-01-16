#include <algorithm>
#include <iostream>

int main()
{
  int arr[5] = {0};

  int n = 5;

  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }

  std::sort(arr, arr + n); // 排序整个数组

  for (int i = 0; i < n; ++i)
    std::cout << arr[i] << " ";

  return 0;
}