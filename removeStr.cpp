#include<stdio.h>
/* 不输出指定字符穿
input: asbcsaasasdas1aas2 as
output: bcsad1a2
*/
int Equal(char *orgin, char *del, int begin)
{
    for(int i = 0; '\0'!=del[i];++i)
    {
        if(del[i]!=orgin[begin+i])
            return 0;
    }
    return 1;
}
int RealSize(const char *str)
{
    int size;
    for(size = 0; str[size]; size++);
    return size;
}
int main()
{
    char origin[100] = "abccabccabasxcv";
    char del[100] = "abc";
    int i = 0;
    int delSize = 0;
    scanf("%s%s", origin, del);
    delSize = RealSize(del);
    while('\0' != origin[i])
    {
        Equal(origin, del, i) ?
        i += delSize:
        printf("%c", origin[i++]);
    }
}