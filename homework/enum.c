#include<stdio.h>

enum score {
    excellent=90, good=80, general=60, fail=0
};

int main()
{
    int n = 60;
    if(n >= excellent) printf("excellent\n");
    else if(n >= good) printf("good\n");
    else if(n >= general) printf("general\n");
    else printf("fail\n");
    return 0;
}