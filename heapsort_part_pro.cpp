
// ds优化版
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 使用迭代方式实现heapify，减少递归开销
void heapify(vector<int>& arr, int n, int i) {
  while (true) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
      largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
      largest = right;
    }
    if (largest == i) break;

    swap(arr[i], arr[largest]);
    i = largest;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  // 构建最大堆
  for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(arr, n, i);
  }

  // 部分排序：只需要前m个最大元素
  int sort_count = min(m, n);
  for (int i = n - 1; i >= n - sort_count; --i) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }

  // 输出结果
  int start = max(n - m, 0);
  for (int i = n - 1; i >= start; --i) {
    cout << arr[i] << ' ';
  }

  return 0;
}
/*#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int>& zu, int n, int i) {
  int largest = i;
  int lr = 2 * i + 1;
  int rr = 2 * i + 2;
  if (lr < n && zu[lr] > zu[largest]) {
    largest = lr;
  }
  if (rr < n && zu[rr] > zu[largest]) {
    largest = rr;
  }
  if (largest != i) {
    swap(zu[i], zu[largest]);
    heapify(zu, n, largest);
  }
}
int main() {
  int n, mm;
  cin >> n >> mm;
  vector<int> zu(n);
  for (int i = 0; i < n; cin >> zu[i], i++);
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(zu, n, i);
  }
  int m = mm > n ? n : mm;
  for (int i = n - 1; i > 0; i--) {
    if (!m) {
      break;
    }
    swap(zu[0], zu[i]);
    heapify(zu, i, 0);
    m--;
  }
  for (int i = n - 1; mm && i > 0; i--, mm--) {
    cout << zu[i] << ' ';
  }
}*/