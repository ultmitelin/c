#include <iostream>
using namespace std;
int main() {
  for (int k = 1; k <= 9; k++) {
    for (int i = k; i <= 9; i++) {
      cout << k << "*" << i << "=" << k * i << " ";
    }
    cout << endl;
  }
}