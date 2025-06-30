#include <cstring>
#include <iostream>

using namespace std;
int main() {
  char a[11] = {0};
  gets(a);
  char b[] = "china";
  string bc;
  memset(a, '6', 5);
  cout << a << endl;
  bc = strupr(a);
  cout << a << endl;
  strncpy(a + strlen(a), b, strlen(b) + 1);
  // 要strlen(b) + 1，加1，把\0也copy过来，否则string没有结束，输出会出错
  cout << a << ' ' << endl;
  int ab = 'A';

  cout << endl << ab;
}
#include <stdio.h>
int main() {
  double a = 18.34567;
  printf("%6f", a);
  char str[] = "hello world";
  char abc[6] = "hello";
  abc[5] = 'A';
  // 这样就使abc输出时结束不了，把后面内存地址中的内容也输出了
  scanf("%3s", str);
  // 这里输入加不加&为什么一样？
  // 数组名本身是地址，不需要加&
  str[3] = 'a';
  // 输入后自动在末尾加“\0”，输出时遇到\0就停止
  printf("\n%s\n", str);
  printf("%s", abc);
}