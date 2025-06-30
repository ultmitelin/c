#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int>& arr) {
  int n = arr.size();
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int x = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > x; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = x;
    }
  }
  // // 初始间隔（gap）设为数组长度的一半，然后逐步缩小
  // for (int gap = n / 2; gap > 0; gap /= 2) {
  //   // 对每个子数组进行插入排序
  //   for (int i = gap; i < n; ++i) {
  //     int temp = arr[i];
  //     int j;

  //     // 对子数组进行插入排序
  //     for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
  //       arr[j] = arr[j - gap];
  //     }

  //     arr[j] = temp;
  //   }
  // }
}

int main() {
  vector<int> arr = {12, 34, 54, 2, 3, 999, 685, 4, 26, 0, 0};

  cout << "排序前: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  shellSort(arr);

  cout << "排序后: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}