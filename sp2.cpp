// 自己根据ds写的
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  while (cin >> s) {
    if (s.find('.') != string::npos) {
      double x = stod(s);
      unsigned char *xx = (unsigned char *)&x;
      for (int i = 0; i < sizeof(double); i++) {
        cout << hex << setw(2) << setfill('0') << (int)xx[i] << ' ';
      }
      cout << '\n';
    } else {
      int x = stoi(s);
      unsigned char *xx = (unsigned char *)&x;
      for (int i = 0; i < sizeof(int); i++) {
        cout << hex << setw(2) << setfill('0') << (int)xx[i] << ' ';
      }
      cout << '\n';
    }
  }
}

// ds版
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void printBytes(int value) {
  unsigned char *bytes = (unsigned char *)&value;
  for (size_t i = 0; i < sizeof(int); ++i) {
    cout << hex << setw(2) << setfill('0') << (int)bytes[i] << " ";
  }
  cout << endl;
}

void printBytes(double value) {
  unsigned char *bytes = (unsigned char *)&value;
  for (size_t i = 0; i < sizeof(double); ++i) {
    cout << hex << setw(2) << setfill('0') << (int)bytes[i] << " ";
  }
  cout << endl;
}

int main() {
  string line;
  while (getline(cin, line)) {
    if (line.find('.') != string::npos) {
      double d = stod(line);
      printBytes(d);
    } else {
      int i = stoi(line);
      printBytes(i);
    }
  }
  return 0;
}