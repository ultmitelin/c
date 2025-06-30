#include <iostream>
using namespace std;
#include <vector>
/*
分区函数：
选择最后一个元素作为基准（pivot）
将所有小于等于基准的元素移动到基准左侧
返回基准的最终位置
*/
struct num {
  int x;
  int n;
};

int swapandpos(vector<num> &arr, int low, int high) {
  int t = arr[high].x;
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j].x <= t) {
      swap(arr[j], arr[++i]);
    }
  }
  swap(arr[high], arr[++i]);
  for (int i = 0; i < 6; i++) cout << arr[i].x << "_" << arr[i].n << ' ';
  cout << '\n';
  return i;
}

void quicksort(vector<num> &arr, int low, int high) {
  if (low < high) {
    int pos = swapandpos(arr, low, high);
    quicksort(arr, low, pos - 1);
    quicksort(arr, pos + 1, high);
  }
}
int main() {
  vector<num> arr(6);
  for (int i = 0; i < 6; cin >> arr[i].x, i++);
  arr[0].n = 0;
  arr[2].n = 1;
  arr[4].n = 2;
  arr[5].n = 3;
  cout << "原始数组：";
  for (int i = 0; i < 6; i++) cout << arr[i].x << "_" << arr[i].n << ' ';
  cout << endl;

  quicksort(arr, 0, 6 - 1);

  cout << "排序后数组：";
  for (int i = 0; i < 6; i++) cout << arr[i].x << "_" << arr[i].n << ' ';
  cout << endl;

  return 0;
}