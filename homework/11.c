#include<stdio.h>
/*
2、	编写函数fun(int m, int *k, int xx[])，
其功能是：将所有大于1小于整数m的非素数存入xx所指数组中，
非素数的个数通过k返回。
 */
// int IsNotPrime(int n)
// {
//     int i;
//     for(i = 2; i<n/2;++i)
//     {
//         if(n%i == 0) return 1;
//     }
//     return 0;
// }
// void fun(int m, int *k, int xx[])
// {
//     int i = 0;
//     *k = 0;
//     for(i = 2; i < m; i++)
//     {
//         if(IsNotPrime(i)) 
//             xx[(*k)++] = i;
//     }
// }
// int main()
// {
//     int xx[100];
//     int k;
//     fun(200, &k, xx);
//     printf("k = %d\n", k);
//     for(int i = 0; i < k; i++)
//         printf("%d\n", xx[i]);
//     return 0;
// }

// 3、	请编写程序，利用malloc函数开辟动态存储单元，顺序存放输入的10个字符串，然后求10个字符串的最大值。
// #include<malloc.h>
// #include<string.h>
// int main()
// {
//     char *max, **row;

//     // 分配每个元素存储空间，每个元素存的一个地址，分配后该空间还没有地址
//     row = (char**)malloc(10*sizeof(char*));
//     if(!row) {
//         printf("malloc error!\n");
//         return 0;
//     }
//     for(int i = 0; i < 10; i++)
//     {
//         row[i] = (char*)malloc(100*sizeof(char));
//         if(!row[i]) {
//             printf("malloc error!\n");
//             return 0;
//         }
//         scanf("%s", row[i]);
        
//     }
//     max = row[0];
//     for(int i = 1; i < 10; i++)
//     {
//         if(strcmp(row[i], max) > 0) max = row[i];
//     }

//     printf("max: %s\n", max);

//     return 0;

// }

// 5、请编写一个程序，比较两个文件，如果相等则返回0；否则返回1。
// int FileCompare(FILE *fp1, FILE *fp2)
// {
//     while (!feof(fp1) && !feof(fp2))
//     {
//         if(fgetc(fp1) != fgetc(fp2)) return 1;
//     }

//     return feof(fp1) && feof(fp2) ? 0: 1;
    
// }
// int main()
// {
//     FILE *fp1 = fopen("txt/from.txt", "r");
//     FILE *fp2 = fopen("txt/newFile.txt", "r");
//     printf("%d", FileCompare(fp1, fp2));
//     fclose(fp1);
//     fclose(fp2);
// }
// 7、利用指向行的指针变量求3 * 5数组各行元素之和。

// #define N 3
// #define M 5
// void main()
// {
// 	int a[N][M] = {1,2,3,4,5, 6,7,8,9,10, 9,8,7,6,5};
// 	int (*p)[5];
// 	int i,j,sum;
// 	for(i=0;i<N;i++)
// 	{ 
// 		p=&a[i]; 
// 		sum=0;
// 		for(j=0;j<M;j++)
// 		{
// 			sum+=*(*p+j);
// 		}
// 		printf("sum of row %d: %d\n",i,sum);
// 	}
// }

// 逆序
// void ReverseBetween(int *arr, int begin, int count)
// {
//     int i = 0, temp;
//     for(arr+=begin-1; i < count/2; i++)
//     {
//         temp = arr[i];
//         arr[i] = arr[count-i-1];
//         arr[count-i-1] = temp;
//     }
// }
// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7};
//     ReverseBetween(arr, 3, 3);
//     for(int i = 0; i < 7; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }


// int main()
// {
//     // 7个元素，每个元素存char*地址, day[7] = *day, char*(*day)，目标类型char*
//     char *day[7] = {
//         "mon", "tues", "wed", "thur", "fri", "sat", "sun"
//     };
//     // 长度未知，当前指向一个长度为7的字符串数组，char[7] (*day;)，目标类型CHAR[7]
//     // char (*day)[7] = "hello";
//     int n = 7;

//     printf("%s\n", day[n-1]);
// }


// 删除数字

int main()
{
    char s[100] = "1as223ASs2132134asdasdyjhtgj234234234dfsdfJKD324";
    char *c, *t;
    c = s;
    while(*c)
        if(*c >='0' && *c <= '9')
            for(t = c; *t; t++)
                t[0] = t[1];
        else c++;
    printf("%s\n", s);
}