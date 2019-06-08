#include<stdio.h>

// 4、编写程序，用结构体类型实现复数的加、减、乘、除运算，每种运算用函数完成。
typedef struct COMPLEX {
    float real;
    float imag;
}COMPLEX;

COMPLEX add(COMPLEX, COMPLEX);
COMPLEX sub(COMPLEX, COMPLEX);
COMPLEX mut(COMPLEX, COMPLEX);
COMPLEX div(COMPLEX, COMPLEX); 
int main()
{
    
    return 0;
}