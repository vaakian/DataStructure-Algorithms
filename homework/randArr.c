#include<stdio.h>
#include<malloc.h>
/* 
11、（10分）定义一个动态数组，长度为变量n，
用随机函数给数组各元素赋值。然后对数组各单元排序，
定义swap函数交换数据单元，要求参数使用指针传递。
*/
int main()
{
    int n = 5;
    int i, j;
    int *arr;
    arr = (int *)malloc(sizeof(int)*n);
    // 随机赋值
    for(i = 0; i < n; ++i)
    {
        arr[i] = rand();
    }
    // 排序
    for(i = 0; i < n; i++)
     {
        for(j = i+1; j < n; j++)
        {
            if(arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
     }
    // 输出
    for(i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}