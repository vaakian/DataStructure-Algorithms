#include <iostream>
#define MAX 200005
using namespace std;
int n, k, p;
int color, price;
int last[MAX];
int sum[MAX];
int cnt[MAX];
int count = 0;
int now;
int main()
{
    cin >> n >> k >> p;
    for (int i = 1; i <= n; ++i, ++cnt[color])
    {
        cin >> color >> price;
        if (price <= p)
            now = i;
        if (now >= last[color])
            sum[color] = cnt[color];
        last[color] = i;
        count += sum[color];  
    }
    cout << count << endl;
    return 0;
}