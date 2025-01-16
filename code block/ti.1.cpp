#include<stdio.h>
#include<math.h>
int main(){
   double a,b,c,asin;
   scanf("%lf %lf",&a,&b);
   c=sqrt(a*a+b*b);
   asin=a/c;

   printf("%.3f",asin);
}
