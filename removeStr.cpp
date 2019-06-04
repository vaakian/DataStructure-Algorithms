#include<stdio.h>
// 不输出重复字符
int Equal(char *orgin, char *del, int begin)
{
    for(int i = 0; '\0'!=del[i];++i)
    {
        if(del[i]!=orgin[begin+i])
            return 0;
    }
    return 1;
}
int main()
{
    char origin[] = "abccabccabasxcv";
    char del[] = "abc";
    int i = 0;
    int delSize = sizeof(del)-1;
    while(i<sizeof(origin))
    {
        Equal(origin, del, i) ?
        i += delSize:
        printf("%c", origin[i++]);
    }
}