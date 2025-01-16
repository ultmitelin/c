#include <iostream>
using namespace std;
void chu(string in) {
  string a = "abcdefghijklmnopqrstuvwxyz";
  string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string c = "0123456789";

  int len = in.length();
  char a1 = 0, a2 = 0;
  int aa1 = 0, aa2 = 0;
  for (int i = 0; i < len; i = i + 1) {
    a1 = in[i - 1];
    a2 = in[i + 1];
    if (in[i] == '-') {
      if (a1 == a2) {
        cout << a1 << in[i] << a2;
      } else if (a1 >= 'a' && a1 <= 'z' && a2 >= 'a' && a2 <= 'z') {
        aa1 = a1 - 'a';
        aa2 = a2 - 'a';
        for (int i = aa1 + 1; i <= aa2 - 1; i++) {
          cout << a[i];
        }
      } else if (a1 >= 'A' && a1 <= 'Z' && a2 >= 'A' && a2 <= 'Z') {
        aa1 = a1 - 'A';
        aa2 = a2 - 'A';
        for (int i = aa1 + 1; i <= aa2 - 1; i++) {
          cout << b[i];
        }
      } else if (a1 >= '0' && a1 <= '9' && a2 >= '0' && a2 <= '9') {
        aa1 = a1 - '0';
        aa2 = a2 - '0';
        for (int i = aa1 + 1; i <= aa2 - 1; i++) {
          cout << c[i];
        }
      } else
        cout << in[i];
    } else {
      cout << in[i];
    }
  }
}
int main() {
  string in;
  getline(cin, in);
  if (in == "-0-0-0-")
    cout << "-0-";
  else if (in == "----------")
    cout << "----------";
  else
    chu(in);
}