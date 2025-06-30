#include <iostream>
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
  vector<int> zu;
  int a;
  while (cin >> a) {
    zu.push_back(a);
  }
  for (auto x : zu) {
    cout << x << ' ';
  }
  cout << endl;
  int n = zu.size();
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(zu, n, i);
  }
  for (int i = n - 1; i > 0; i--) {
    swap(zu[0], zu[i]);
    heapify(zu, i, 0);
  }
  for (auto x : zu) {
    cout << x << ' ';
  }
}