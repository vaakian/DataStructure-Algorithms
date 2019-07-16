#include <bits/stdc++.h>
using namespace std;

typedef struct PERIOD
{
    int begin[2];
    int end[2];
} PERIOD;
int get_distance(PERIOD node)
{
    int from, to, result;
    // 开始时间应该迁就最迟的
    from = max(node.begin[0], node.begin[1]);
    // 结束时间迁就最早的
    to = min(node.end[0], node.end[1])
    result = to - from;
    return result < 0 ? 0 : result;
}
int main()
{
    int n, i, sum = 0;
    vector<PERIOD> all;
    PERIOD temp;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> temp.begin[0] >> temp.end[0];
        all.push_back(temp);
    }
    for (i = 0; i < n; i++)
    {
        cin >> all[i].begin[1] >> all[i].end[1];
    }
    for (PERIOD p : all)
    {
        sum += get_distance(p);
    }
    cout << sum << endl;
    return 0;
}