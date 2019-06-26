#include<stdio.h>
/*
    25、根据程序提示从键盘输入一个已存在的文本文件的完整文件名，
    并再输入一个新文本文件的完整文件名，
    然后编程将已存在文本文件中的内容全部拷贝到新文本文件中去，
    并编程实现在显示器上显示源文件内容。
 */
void CopyFile(char *fname1, const char *fname2)
{
    FILE *dest = fopen(fname1, "w");
    FILE *origin = fopen(fname2, "r");
    char c;
    if(origin && dest) {
        while((c=fgetc(origin)) != EOF)
        {
            // fputc, fgetc会移动文件指针
            fputc(c, dest);
            putchar(c);
        }
    } else {
        printf("failed to open file.\n");
    }
}

int main()
{
    char existFileName[100];
    char newFileName[100];
    printf("input existFileName:");
    scanf("%s", existFileName);
    printf("input newFileName:");
    scanf("%s", newFileName);
    CopyFile(newFileName, existFileName);
    return 0;
}