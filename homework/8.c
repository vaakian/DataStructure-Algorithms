#include<stdio.h>
#define N 10
// 定义一个结构类型数组(包括年、月、日)，实现输入十个日期，按日期从大到小排序输出。
typedef struct  DATE
{
    int year;
    int month;
    int day;
}DATE;
int sum(DATE date)
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 12};
    int s = date.year*365+date.day;
    for(int i = 0; i < date.month; i++) s += days[i];
    if(date.month > 2)
        if(date.year%400 == 0 || date.month%4==0 && date.month%100!=0)
            ++s;
    return s;
}
int main()
{
    int i, j;
    DATE d[N]= {
        {2019, 2, 3},
        {2019, 3, 3},
        {2000, 1, 1},
        {2019, 4, 4},
        {2019, 4, 5},
        {1999, 12, 31},
        {2013, 11, 25},
        {2016, 5, 13},
        {2002, 9, 22},
        {2015, 2, 2}
    };
    DATE temp;
    // 开始排序
    for(i = 0; i < N; i++)
    {
        for(j = i+1; j < N; j++)
        {
            if(sum(d[i]) < sum(d[j])) 
            {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
        printf("%d-%d-%d = %d\n", d[i].year, d[i].month, d[i].day, sum(d[i]));
    }
    return 0;
}