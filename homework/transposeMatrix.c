#include<stdio.h>
// 21、编写一个函数（参数用指针）将一个3 * 3的矩阵转置
void TransposeMatrix(int (*row)[3])
{
    int x, y, t;
    for(x = 0; x < 3; x++)
    {
        for(y = 0; y < 3; y++)
        {
            t = row[x][y];
            row[x][y] = row[y][x];
            row[y][x] = t;
        }
    }
}
void Print(int (*row)[3])
{
    int x, y, t;
    for(x = 0; x < 3; x++)
    {
        for(y = 0; y < 3; y++)
        {
            printf("%d ", row[y][x]);
        }
        putchar('\n');
    }
}
int main()
{
    int row[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    TransposeMatrix(row);
    Print(row);
    return 0;
}