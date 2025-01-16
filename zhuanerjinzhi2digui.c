#include <stdio.h>
void Binary(int n);
//=========================主函数main==========================//
int main()
{
  int n;
  printf("请输入十进制数：");
  scanf("%d", &n);
  Binary(n);

    return 0;
}
//==========================函数功能区=========================//
void Binary(int n)
{
  short t = 0;
  if (n != 0)
  {
    t = n % 2;
    n = n / 2;
    Binary(n);
    printf("%d\n", t);
  }
}
