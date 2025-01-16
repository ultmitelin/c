#include <stdio.h>
#include <stdlib.h>

int main() {
  int num = 42;
  char result[20];

  // 调用 itoa() 函数将整数转换为字符串
  if (itoa(num, result, 10)) {
    printf("The integer %d in text form is: %s\n", num, result);
  } else {
    printf("Failed to convert number to string.\n");
  }

  return 0;
}