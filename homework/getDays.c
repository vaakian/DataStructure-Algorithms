#include<stdio.h>

// 22、定义一个结构类型变量(包括年、月、日)，实现输入一个日期显示它是该年第几天。 

typedef struct DATE
{
    int year;
    int month;
    int day;
}DATE;

int GetDays(DATE date)
{
    int days[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
    int sum = date.day;
    for(int i = 1; i < date.month; i++)
        sum += days[i];
    if(date.month > 2)
        if(date.year%400==0 || date.year%4==0 && date.year%100!=0)
            ++sum;
    return sum;
}
int main()
{
    DATE date = {2016, 3, 1};
    printf("%d\n", GetDays(date));
    return 0;
}