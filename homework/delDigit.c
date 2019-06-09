#include<stdio.h>
/* 字符串往前移动后，s就跳到下一个去了。
    但是不排除下一个也是数字，所以如果移动一位后，还应该跳到原点来继续判断。
    如：
        s[]= as12xcv5
        第s指向s[2]=1，移动后s = as2xcv5 但是s指向s[3]=x了，漏掉了2。
    核心来讲：
        如果当前s指向的不是数字了，就继续往后走。
*/
void DelDigit(char *s)
{
    while('\0' != *s)
    {
        if(*s>='0' && *s<='9') {
            for(char *t = s; *t; ++t)
                *t = *(t+1);
        }else {
            s++;
        }
        
    }
}
// 递归写法
void DelDigit2(char *s)
{
    if('\0' != *s)
    {
        if(*s>='0' && *s<='9') {
            for(char *t = s; *t; ++t)
                *t = *(t+1);
            // 已经往前移动了，继续查找相当于找下一位。
            DelDigit(s);
        }else {
            // 如果不是数字，未移动，则手动往后走。
            DelDigit(s+1);
        }
    }
}
int main()
{
    char s[] = "a1s123123d56";

    DelDigit2(s);

    printf("%s\n", s);
    return 0;
}