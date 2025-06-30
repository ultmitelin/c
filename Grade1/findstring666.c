/***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/
#include <stdio.h>
#include <string.h>
int strReverseIndex(char s[], char t[])
/* precondition: NULL
postcondition: return index of t in s from right to left, -1 if none
*/
{
  // TODO: your function definition
  int n = strlen(t);
  int m = strlen(s);
  int ci = 0;
  int i = m - n;
  for (; i >= 0; i--) {
    int flag =
        0;  // 每次进入要把标志归零，因为不合适时就变，但下次判断要在0基础上而不是变了的基础上
    int wei = i;
    for (int j = 0; j < n; j++) {
      if (s[wei++] != t[j]) {
        flag++;
        // printf("%d %d\n", flag, i);
        break;
      }
    }
    if (flag == 0) {
      ci = 1;
      break;
    }
  }
  if (ci == 1) {
    return i;
  } else
    return -1;
}
/***************************************************************/
#define N 80
int main() {
  char s[N + 1], t[N + 1];
  scanf("%s%s", s, t);
  //********** strReverseIndex is called here ********************
  printf("%d\n", strReverseIndex(s, t));
  //**************************************************
  return 0;
}