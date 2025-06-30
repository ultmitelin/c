#include <iostream>
using namespace std;
void maopao(int (&zu)[]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10 - i - 1; j++) {
      if (zu[j] < zu[j + 1]) {
        swap(zu[j], zu[j + 1]);
      }
    }
  }
  return;
}
int main() {
  int zu[10];
  for (int i = 0; i < 10; i++) {
    cin >> zu[i];
  }
  maopao(zu);
  for (auto x : zu) {
    cout << x << ' ';
  }
  return 0;
}