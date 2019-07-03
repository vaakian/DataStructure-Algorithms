#include<stdio.h>
int isPower2(int num)
{
    return !(num & (num - 1));
}
int main()
{
    printf("%d", isPower2(65536));
    return 0;
}