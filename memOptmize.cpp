#include<iostream>
using namespace std;
/* 斐波那契记忆优化对比
    before:13529
    after:37
*/

int mem[100] = {0};
int count = 0;
int fib(int n) 
{
    count++;
    if(n <= 2)
        return 1;
    if(!mem[n]) {
        mem[n] = fib(n-1) + fib(n-2);
    }
    return mem[n];
}
int fib2(int n) 
{
    count++;
    if(n <= 2)
        return 1;
    return fib2(n-1) + fib2(n-2);
}

int main()
{

    cout<<fib2(20)<<endl;
    cout<<"before:"<<count<<endl;
    
    count = 0;
    cout<<fib(20)<<endl;
    cout<<"after:"<<count<<endl;
    
    return 0;
}