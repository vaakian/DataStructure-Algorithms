#include<iostream>
#include<vector>
using namespace std;

typedef struct PERIOD {
    int begin;
    int end;
}PERIOD;
int get_distance(PERIOD h, PERIOD m)
{
    int from, to, result;
    // 开始时间应该迁就最迟的
    from = h.begin>m.begin ? h.begin: m.begin;
    // 结束时间迁就最早的
    to = h.end<m.end ? h.end: m.end;
    result = to - from;
    return result<0 ? 0: result;
}
int main()
{
    int n, i, sum = 0;
    // 两个vector，存放各自的时间段
    vector<PERIOD> H, M;
    PERIOD temp;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>temp.begin>>temp.end;
        H.push_back(temp);
    }
    for(i = 0; i < n; i++)
    {
        cin>>temp.begin>>temp.end;
        M.push_back(temp);
    }
    // n*n对比时间段，算出时间
    for(auto h: H) {
        for(auto m: M) {
            sum+=get_distance(h, m);
        }
    }
    cout<<sum<<endl;
    return 0;
}