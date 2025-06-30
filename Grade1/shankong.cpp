#include <cstring>
#include <iostream>
using namespace std;
std::string removeSpaces(std::string str);
int main() {
  char str[] = "H e  l l   o, World!";
  string str1;
  str1 = removeSpaces(str);
  cout << str1;
}
std::string removeSpaces(std::string str) {
  for (size_t i = 0; i < str.length();) {
    if (str[i] == ' ') {
      str.erase(i, 1);
    } else {
      ++i;
    }
  }
  return str;
}