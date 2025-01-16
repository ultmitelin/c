#include <iostream>
using namespace std;
// 思路要清晰，别乱，下次带个稿纸多写写

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int N;
    cin >> N;
    // sum1 = a;
    // while (sum1 > 2) {
    //   sum = sum + sum1 + sum1 / 3;

    //   sum1 = sum1 % 3 + sum1 / 3;
    // }
    int totalCandies = 0;  // 总共获得的糖果数
    int wrappers = 0;      // 拥有的糖果纸数

    // 首先用所有的钱买糖果
    totalCandies = N;
    wrappers = N;

    // 用糖果纸兑换更多的糖果
    while (wrappers >= 3) {
      int newCandies = wrappers / 3;         // 可以兑换的糖果数
      totalCandies += newCandies;            // 增加兑换的糖果数
      wrappers = wrappers % 3 + newCandies;  // 更新剩余的糖果纸数
    }
    cout << totalCandies << endl;
  }
}