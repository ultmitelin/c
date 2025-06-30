#include <stdio.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main() {
  // double i;
  // for (i = 0; i < 10.0; i += 0.1) printf("%.1f\n", i);
  // cout << setbase(6) << 32 << endl;
  // fstream fin("input.txt");
  // string s;
  // while (fin >> s) {
  //   cout << s << endl;
  // }
  char x;
  while (x = getchar() != EOF) {
    cout << x;
  }
  return 0;
  // string s = "123";
  // char a = 'A';
  // cout << true;
}
