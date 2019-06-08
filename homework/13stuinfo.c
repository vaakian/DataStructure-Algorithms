#include<stdio.h>
#include<string.h>
/*
13、定义描述学生信息（学号、姓名、性别、出生日期、4门课程成绩和平均分）的结构体类型。 
1）（5分）定义输入单个学生信息的函数Input(struct stu *a) ;
2）（5分）定义输出单个学生信息的函数Output(struct stu a) ;
3）（10分）请编写按姓名进行查找的函数Searchname，若找到，返回表示该学生的信息，不排除有有同名同姓的情况；否则，返回 查无此人。
4）（10分）请编写函数Sortname,它的功能是:按每个学生的名字由小到大输出学生的记录。

 */
typedef struct DATE
{
    int year;
    int month;
    int day; 
    /* data */
}DATE;

typedef struct STU {
    int num;
    char name[20];
    char sex;
    DATE birth;
    float score[4];
    float ave;
}STU;

void Input(STU *a);
void Output(STU *a);
// 3）（10分）请编写按姓名进行查找的函数Searchname，若找到，返回表示该学生的信息，不排除有有同名同姓的情况；否则，返回 查无此人。
void SearchName(const char *name, STU *stus, int stuSize)
{
    int count = 0;
    for(int i = 0; i < stuSize; i++)
    {
        if(strcmp(name, stus[i].name) == 0)
        {
            count++;
            Output(stus+i);
        }
    }
    if(count == 0)
        printf("没有找到!");
}
// 4）（10分）请编写函数Sortname,它的功能是:按每个学生的名字由小到大输出学生的记录。
void SortName(STU *stus, int stuSize)
{
    int i,j;
    for(i = 0; i < stuSize; i++)
    {
        for(j = i+1; j < stuSize; j++)
        {
            if(strcmp(stus[i].name, stus[j].name) > 0)
            {
                STU temp = stus[i];
                stus[i] = stus[j];
                stus[j] = temp;
            }
        }
        Output(stus+i);
    }
}
int main()
{
    STU stus[4];
    for(int i=0; i<4; i++)
    {
        Input(stus+i);
    }
    SortName(stus, 4);
    return 0;
}

void Input(STU *a) 
{
    DATE *birth = &a->birth;
    scanf("%d%s%d%d%d%f%f%f%f",
    &a->num,
    a->name,
    &birth->year,
    &birth->month,
    &birth->day,
    a->score,
    a->score+1,
    a->score+2,
    a->score+3
    );
    // 2018 marry 2019 2 3 80 87 65 99 
}

void Output(STU *a)
{
    DATE *birth = &a->birth;
    printf("%d %s %d %d %d %.2f %.2f %.2f %.2f\n",
    a->num,
    a->name,
    birth->year,
    birth->month,
    birth->day,
    a->score[0],
    a->score[1],
    a->score[2],
    a->score[3]
    );
}
