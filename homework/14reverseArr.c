#include<stdio.h>
#define N 11

// 整个翻转
void Reverse(int *arr)
{
    int i, j, temp;
    // for(i = 0, j = N-1; i<j; i++, j--)
    // {
    //     temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;
    // }
    // 不需要两个偏移量
    for(i = 0; i<N/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[N-i-1];
        arr[N-i-1] = temp;
    }
}

// 从某个开始，到某一个结束，进行翻转
void Reverse2(int *arr, int from, int count)
{
    int i, temp;
    // 把arr+from-1 设置为数值起点
    // 要翻转的数组终点是count-1
    // 所以把(0, count) 看做数组直接翻转就可以了
    arr += from - 1;
    for(i = 0; i<count/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[count-1-i];
        arr[count-1-i] = temp;
    }
}

// 递归翻转法，i是开始，j是结尾。
void Reverse3(int *arr, int i, int j)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    if(i<j) Reverse3(arr, i+1, j-1);
}

int main()
{
    int arr[N] = {1,2,3,4,5,6,7,8,9,0,55};
    Reverse3(arr, 0, N-1);
    for(int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }
}