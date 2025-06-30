#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
struct Triple {
  int r;  //  row  index
  int c;  // column index
  int value;
};
bool cmp(Triple a, Triple b) {
  if (a.r != b.r) {
    return a.r < b.r;
  } else
    return a.c < b.c;
}
int main() {
  vector<Triple> zu[2];
  int r, c;
  cin >> r >> c;
  int num0;
  cin >> num0;
  for (int i = 0; i < num0; i++) {
    Triple x;
    cin >> x.r >> x.c >> x.value;
    zu[0].push_back(x);
  }
  sort(zu[0].begin(), zu[0].end(), cmp);
  cin >> r >> c;
  int num1;
  cin >> num1;
  for (int i = 0; i < num1; i++) {
    Triple x;
    cin >> x.r >> x.c >> x.value;
    zu[1].push_back(x);
  }
  sort(zu[1].begin(), zu[1].end(), cmp);
  int n = num0 + num1;
  vector<Triple> result;
  for (int i = 0; i < num0; i++) {
    int flag = 1;
    for (int j = 0; j < num1; j++) {
      if (zu[0][i].c == zu[1][j].c && zu[0][i].r == zu[1][j].r) {
        Triple x;
        x.c = zu[0][i].c;
        x.r = zu[0][i].r;
        x.value = zu[0][i].value + zu[1][j].value;
        result.push_back(x);
        flag = 0;
      }
    }
    if (flag == 1) result.push_back(zu[0][i]);
  }
  for (int i = 0; i < num1; i++) {
    int flag = 1;
    for (int j = 0; j < num0; j++) {
      if (zu[1][i].c == zu[0][j].c && zu[1][i].r == zu[0][j].r) {
        flag = 0;
      }
    }
    if (flag == 1) result.push_back(zu[1][i]);
  }
  sort(result.begin(), result.end(), cmp);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i].r << ' ' << result[i].c << ' ' << result[i].value << endl;
  }
}
