// 函数说明：
// void del(char s[]);
// Precondition：s存放一个字符串;
// Postcondition：删除s中所有空格，其余字符按原来顺序存放在s中。

#include <stdio.h>
#include <string.h>
void del(char s[])
{
  // 函数实现
  int slow = 0, fast = 0;
  while (s[fast] != '\0')
  {
    if (s[fast] == ' ')
    {
      fast++;
      continue;
    }

    s[slow] = s[fast];
    slow++;
    fast++;
  }

  s[slow] = '\0';
}
int main()
{
  char s[110000];
  gets(s); // 输入一行字符
  del(s);
  printf("%s\n", s);
  return 0;
}