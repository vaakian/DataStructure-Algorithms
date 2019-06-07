#include <stdio.h>
#define N 2
struct DATE{
        int year;
        int month;
        int day;
};
struct TEACHER_INFO{
        char name[20];
        char sex[10];
        struct DATE birthday;
        char addr[30];
        char p_number[20];
        int income;
};

void Input(struct TEACHER_INFO*);
int main()
{
        int k , i;
        struct TEACHER_INFO teachers[N];
        printf("输入多少名老师信息：");
        scanf("%d", &k);
        for(i = 0; i < k; i++)
        {
            Input(teachers+i);
        }
        printf("姓名\t性别\t出生日期\t\t住址\t\t\t电话\t\t月收入\n");
        for(i = 0; i < k; i++)
        {
            printf("%d.%s\t%s\t", i+1,teachers[i].name, teachers[i].sex);
            printf("%d年%d月%d日\t\t" , teachers[i].birthday.year , teachers[i].birthday.month , teachers[i].birthday.day);
            printf("%s\t\t%s\t\t%d\n" , teachers[i].addr , teachers[i].p_number, teachers[i].income);
        }
        return 0;
}

void Input(struct TEACHER_INFO *teacher)
{
        struct DATE* birth = &teacher->birthday;
        scanf("%s%s%d%d%d%s%s%d", 
            teacher->name, 
            teacher->sex,
            &birth->year,
            &birth->month,
            &birth->day,
            teacher->addr,
            teacher->p_number,
            &teacher->income
        );
}
