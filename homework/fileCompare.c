#include<stdio.h>

// 5、请编写一个程序，比较两个文件，如果相等则返回0；否则返回1。

int Compare(FILE *f1, FILE *f2)
{
    // 有一个文件到尾部则终止
    while(!feof(f1) && !feof(f2))
    {
        // 不相等则返回
        if(fgetc(f1) != fgetc(f2)) return 1;
    }
    /* 
        如果没有不同字符(即循环结束)则依然有两种情况，
        1. 任意一个文件未到结尾，则两个文件肯定不同。
        2. 两个都到结尾了，则前面对比都成功，相同。
        如：app和ap比较 
    */
    return feof(f1) == feof(f2) ? 0: 1;
}

int main()
{
    FILE *f1 = fopen("1.txt", "r");
    FILE *f2 = fopen("2.txt", "r");

    printf("%d\n", Compare(f1, f2));

// 关闭文件
    fclose(f1);
    fclose(f2);
    return 0;
}