
#include<iostream>
using namespace std;
int main()
{
    int r,y,g,n,k,t;
    int sum=0;
    cin>>r>>y>>g;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>k>>t;
        if(k==0||k==1)
        // 0是走路耗时，1是红灯等待耗时
            sum += t;
        else if(k==2)
        // 2是黄灯，耗时= 黄灯剩余时间 + 红灯总时间
        //（亮灯顺序：红绿黄）
            sum += t+r;
        else
        // 3是绿灯，不管显示多少可以忽略，直接走。
            continue
    }
    cout<<sum<<endl;
    return 0;
}
