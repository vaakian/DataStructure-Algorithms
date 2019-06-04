#include<stdio.h>

int main()
{
    char s[] = "aacbbb";
    int count = 1;
    for(int i = 1; i<=sizeof(s); ++i) {
        if (s[i] == s[i-1]) ++count;
        else {
            count == 1 ?
                printf("%c", s[i-1]):
                printf("%d%c", count, s[i-1]);
            count = 1;
        }
    }
}