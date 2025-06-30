#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int zu[3][5] = {
      {15, 16, 18, 99, 16}, {19, 16, 1155, 18, 99999}, {15, 17, 666, 33, 0}};
  for (int i = 0; i < 3; i++) {
    sort(zu[i], zu[i] + 5);
    for (int j = 0; j < 5; j++) {
      cout << zu[i][j] << ' ';
    }
    cout << endl;
  }
  sort(*zu, *zu + 15);
  // sort(*zu.begin(), *zu.end());也不对

  // sort(zu, zu + 15 * sizeof(int) * 2);不对
  // 二维数组排序时要加  *  ，否则运行不了；
  cout << zu[2][3];
}
