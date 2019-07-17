// 二分搜索根、数组搜索
#include <bits/stdc++.h>
#define END 1e-6
using namespace std;
// 迭代写法
        /*  low---- mid ----high
            mid*mid大，就从low~mid找
            否则从mid~high找
        */
double search_sqrt(double n)
{
    double high, mid, low;
    high = n;
    low = 0;
    while (true)
    {
        mid = (high + low) / 2;
        if (high - low <= END || mid * mid == n)
            return mid;
        else if (mid * mid > n)
            high = mid;
        else
            low = mid;
    }
}
// 递归写法
double search_sqrt_rec(double n, double low, double high)
{
    double mid = (high + low) / 2;
    if (high - low <= END || mid * mid == n)
        return mid;
    return mid * mid > n ? search_sqrt_rec(n, low, mid) : search_sqrt_rec(n, mid, high);
}
// 柯里化
double search_sqrt2(double n)
{
    return search_sqrt_rec(n, 0, n);
}
bool search_arr(vector<int> arr, int search_val)
{
    int high, low, mid;
    low = 0;
    high = arr.size();
    while (1)
    {
        mid = (high + low) / 2;
        if (arr[mid] == search_val)
            return true;
        if (high - low <= 1)
            return false;
        if (arr[mid] > search_val)
            high = mid;
        else
            low = mid;
        mid = (high + low) / 2;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 9};
    double n = 5345.25;
    // cin >> n; 求根，sqrt(n)
    printf("sqrt(%.2lf) = %lf\n", n, search_sqrt2(n));
    printf("sqrt(%.2lf) = %lf\n", n, search_sqrt(n));
    // arr搜索
    if (search_arr(arr, 5))
        cout << "find!\n";
    else
        cout << "no find!\n";
    return 0;
}