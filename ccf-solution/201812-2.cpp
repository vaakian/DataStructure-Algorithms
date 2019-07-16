/*
https://blog.csdn.net/tigerisland45/article/details/78420636
https://blog.csdn.net/wl16wzl/article/details/79344292
https://blog.csdn.net/wingrez/article/details/85111975

python:
https://blog.csdn.net/weixin_41706011/article/details/86594586

模拟考试：
http://118.190.20.162/home.page
http://118.190.20.162/UserEnter.do?USERKEY=%3C17683733332%3E&NAME=%3C%E7%86%8A%E7%BB%B4%E5%BB%BA%3E
 */
#include<iostream>
using namespace std;
int consume_time(int k, int t, int sum, int r, int y, int g)
{
    int time = r + y + g;
    int period;
    // 落在的时间段 = 3个灯循环时间 - 出发时剩余时间 + 从开始到现在耗费时间
    if (k == 0)
        return t;
    // 求落在的区间
    else if (k == 1)
        period = r - t + sum;
    else if (k == 2)
        period = r + g + y - t + sum;
    else
        period = r + g - t + sum;
    // cout<<endl<<k<<" "<<t<<"period"<<period<<endl;
    period = period % time;
    // 红灯
    if (period <= r) {
        cout<<"红灯！"<<endl;
        return r - period;
    }
    // 绿灯直接通过
    else if (period <= r + g) {
        cout<<"绿灯！"<<endl;
        return 0;
    }
    // 黄灯
    else {
        cout<<"黄灯！"<<endl;
        return r + g + y - period;
    }
}
int main()
{
    int r, y, g, n, k, t;
    int sum = 0;
    cin >> r >> y >> g;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> k >> t;
        int cur = consume_time(k, t, sum, r, y, g);
        cout<<"cur: "<<cur<<endl;
        sum+=cur;
    }
    cout << sum << endl;
    return 0;
}
