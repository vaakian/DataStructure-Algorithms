#include <bits/stdc++.h>

using namespace std;
// 选择不相邻的数，求最大的方案
int arr[7] = {1, 2, 4, 1, 7, 8, 3};
// 小问题解决大问题
int rec_opt(int i)
{
    if (i == 0)
        return arr[0];
    if (i == 1)
        return max(arr[0], arr[1]);
    return max(rec_opt(i - 2) + arr[i], rec_opt(i - 1));
}
int dp_opt(int arr, int i)
{
    int j;
    int opt[7] = {arr[0], max(arr[0], arr[1])};
    for (j = 2; j <= i; j++)
    {
        opt[j] = max(opt[j - 2] + arr[j], opt[j - 1]);
    }
    return opt[j - 1];
}
int main()
{
    cout << dp_opt(6) << endl;
    return 0;
}
// 2
opt[]