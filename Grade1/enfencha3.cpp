/***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/

#include <stdio.h>

int binarySearch(int a[], int n, int x) {
  // TODO: your function definition
  int low = 0, high = n - 1;
  int med = 0;
  int flag = -1;
  while (low <= high) {
    med = (low + high) / 2;
    if (x == a[med]) {
      flag = med;
      break;
    } else if (x > a[med]) {
      high = med - 1;
    } else {
      low = med + 1;
    }
  }

  if (flag == -1) {
    return -1;
  } else
    return flag;
}

/***************************************************************/
#define N 100000
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  //********** binarySearch is called here *************
  int q, x;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &x);
    printf("%d\n", binarySearch(a, n, x));
  }
  //**************************************************
  return 0;
}