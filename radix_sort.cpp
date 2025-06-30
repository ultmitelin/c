#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<vector<int>> zu(10);
  vector<int> zu0;
  int x;
  while (cin >> x) {
    zu0.push_back(x);
  }
  int maxx = zu0[0];
  for (auto a : zu0) {
    if (a > maxx) {
      maxx = a;
    }
  }
  int maxdigit = 0;
  while (maxx) {
    maxx /= 10;
    maxdigit++;
  }
  for (int i = 0; i < maxdigit; i++) {
    int w = 1, m = i;
    // w从1开始，然后逐次乘10，别搞错，别想歪
    while (m) {
      w *= 10;
      m--;
    }
    for (auto y : zu0) {
      zu[(y / w) % 10].push_back(y);
    }
    zu0.clear();
    for (auto &a : zu) {
      // 这里要用引用，否则就clear了个寂寞
      for (auto b : a) {
        zu0.push_back(b);
        //     // 可以用erase，但操作太多，不如最后直接clear
      }
      a.clear();
    }
  }
  for (auto x : zu0) {
    cout << x << ' ';
  }
}
/*  kimi版

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 基数排序
void radixSort(vector<int>& arr) {
    // 找到最大值，确定最大位数
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // 计算最大位数
    int maxDigits = 0;
    while (maxVal > 0) {
        maxVal /= 10;
        maxDigits++;
    }

    // 桶数组，用于存放每一轮的数字
    vector<queue<int>> buckets(10);

    // 按位排序
    for (int digit = 0; digit < maxDigits; digit++) {
        // 将数字放入对应的桶中
        for (int i = 0; i < arr.size(); i++) {
            int bucketIndex = (arr[i] / static_cast<int>(pow(10, digit))) % 10;
            buckets[bucketIndex].push(arr[i]);
        }

        // 从桶中取出数字，放回数组
        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!buckets[i].empty()) {
                arr[index++] = buckets[i].front();
                buckets[i].pop();
            }
        }
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}*/