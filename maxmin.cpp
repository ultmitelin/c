#include <iostream>

using namespace std;

int main()
{
    printf("%d %d\n",CHAR_MIN,CHAR_MAX);
    printf("%d %d\n",INT_MIN,INT_MAX);
    printf("%d %llu\n",0,UINT_MAX);
    printf("%d %d\n",SHRT_MIN,SHRT_MAX);
    printf("%lld %lld\n",LLONG_MIN,LLONG_MAX);
    printf("%d %llu\n",0,ULLONG_MAX);
}
