#include<stdio.h>

void Fshow(FILE* f)
{
    char c;
    while((c=fgetc(f)) != EOF)
    {
       
        putchar(c);
    }
    /*
    #define EOF -1
    这种写法最后会输出EOF，即-1
        while (!feof(f))
        {
            getc 会移动文件指针
            putchar(fgetc(f));
        }
     */
    
}

int main()
{
    char c;

    FILE *f = fopen("txt/from.txt", "r");
    FILE *t = fopen("txt/to.txt", "w"); 
    // 显示源文件内容
    Fshow(f);
    fseek(f, 0, 0);
    /*
        fseek(指针，偏移，从哪里开始)
            SEEK_SET： 文件开头 0
            SEEK_CUR： 当前位置 1
            SEEK_END： 文件结尾 2
        example:
            fseek(f, 0, 0) 到开头
            fseek(f, 2, 1) 从当前位置偏移两位
            fseek(f, 0, 2) 到结尾
    */
    // 避免前一次输出混淆
    putchar('\n');
    while((c = fgetc(f))!= EOF)
    {
        if(c <= 'Z' && c >= 'A') c+=32;
        fputc(c, t);
        // 输出目标内容
        putchar(c);
        // fputs("saasd", fp); 
        // scanf(fp, "saasd");
    }
    fclose(f);
    fclose(t);
    return 0;
}